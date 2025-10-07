/*
Parallel Fetcher
*/

#include <iostream>
#include <fstream> // open(), close()
#include <sstream> //istring, ostring
#include <string> // strings
#include <unistd.h> // fork, execlp
#include <sys/wait.h> // wait
#include <vector>

using namespace std;

int main() {
  vector<pid_t> children;
  ifstream infile("input.txt");
  if (!infile) {
    cerr << "Error: Cant open input.txt\n";
    return 0;
  }

  string line;
  int count = 1;

  cout << "Parent process started\n";
  cout << "Parent PID: " << getpid()
      << ", UID: " << getuid()
      << ", GID: " << getgid() << "\n\n";

  while (getline(infile, line))
  {
    istringstream iss(line);
    double lat, lon;
    if (!(iss >> lat >> lon))
      continue; // skip invalid lines

    pid_t pid = fork();

    if (pid < 0)
    {
      cerr << "Error: fork failed\n";
      return 1;
    }
    else if (pid == 0)
    {
      // Child process
      cout << "Child " << count << " created.\n";
      cout << " PID: " << getpid()
           << ", PPID: " << getppid()
           << ", UID: " << getuid()
           << ", GID: " << getgid() << "\n";

      string filename = "file" + to_string(count) + ".json";
      string url = "https://api.open-meteo.com/v1/forecast?latitude=" +
                      to_string(lat) + "&longitude=" +
                      to_string(lon) + "&current_weather=True";

      execlp("/usr/bin/curl", "curl", "-s", "-o", filename.c_str(),
              url.c_str(), (char *)NULL);
      perror("execlp failed");
      _exit(1);
    }
    else
    {
        children.push_back(pid);
        count++;
    }
  }

  for (pid_t pid : children)
  {
    waitpid(pid, NULL, 0);
  }

  cout << "All weather files downloaded\n";
  return 0;
}

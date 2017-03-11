#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000000
#define M 1000

char buffer[N], scan[N];
char idx[M], verdict[M], contest_id[M], link[M], id[M];

int main(int argc, char *argv[]) {
  FILE *f1 = NULL, *f2 = NULL, *f3 = NULL;
  f1 = fopen("codeforces.txt", "rw+");
  f2 = fopen("TmpDirCFCodes/download.txt", "w");
  f3 = fopen("list.txt", "w");
  if (f1 == NULL || f2 == NULL || f3 == NULL) {
    puts("Necessary files could not be opened, exiting.");
    exit(1);
  }
  buffer[0] = '\0';
  fgets(buffer, N, f1);
  for (int i = 0; buffer[i] != '\0'; i++) {
    if (buffer[i] == '\"') {
      int j;
      for (j = i + 1; buffer[j] != '\0' && buffer[j] != '\"'; j++) {
        scan[j - i - 1] = buffer[j];
      }
      scan[j - i - 1] = '\0';
      if (! strcmp(scan, "contestId")) {
        int k = 0;
        for (j = j + 2; buffer[j] != '\0' && buffer[j] != ','; j++) {
          contest_id[k++] = buffer[j];
        }
        contest_id[k] = '\0';
      } else if (! strcmp(scan, "index")) {
        int k = 0;
        for (j = j + 3; buffer[j] != '\0' && buffer[j] != '\"'; j++) {
          idx[k++] = buffer[j];
        }
        idx[k] = '\0';
      } else if (! strcmp(scan, "id")) {
        int k = 0;
        for (j = j + 2; buffer[j] != '\0' && buffer[j] != ','; j++) {
          id[k++] = buffer[j];
        }
        id[k] = '\0';
      } else if (! strcmp(scan, "verdict")) {
        int k = 0;
        for (j = j + 3; buffer[j] != '\0' && buffer[j] != '\"'; j++) {
          verdict[k++] = buffer[j];
        }
        verdict[k] = '\0';
        if (! strcmp(verdict, "OK")) {
          sprintf(link, "http://codeforces.com/contest/%s/submission/%s\n", contest_id, id);
          fprintf(f2, "%s", link);
          fprintf(f3, "%s,%s,%s,", id, contest_id, idx);
        }
      }
    }
  }
  fclose(f1);
  fclose(f2);
  fclose(f3);
  return 0;
}

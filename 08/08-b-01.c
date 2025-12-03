#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define DICT_FILE "/usr/share/dict/words"

char *load_dict_file(void);
void free_dict_buf(char*);

int main()
{
  char *dict_buf;

  dict_buf = load_dict_file();

  /* write preprocessing here */

  free_dict_buf(dict_buf);

  /* write spell checking here */

  return 0;
}

char *load_dict_file(void)
{
  FILE *fp;
  struct stat stat_buf;
  size_t file_size;
  char *buf;
  
  if ((fp = fopen(DICT_FILE, "r")) == NULL) {
    fprintf(stderr, "failed to open file: %s\n", DICT_FILE);
    exit(1);
  }
  if (fstat(fileno(fp), &stat_buf) == -1) {
    fprintf(stderr, "failed to get file status\n");
    exit(1);
  }
  file_size = stat_buf.st_size;
  buf = (char*)malloc(file_size + 1);
  if (buf == NULL) {
    fprintf(stderr, "out of memory\n");
    exit(1);
  }
  if (fread(buf, sizeof(char), file_size, fp) != file_size) {
    fprintf(stderr, "failed to read file\n");
  }
  fclose(fp);
  buf[file_size] = '\0';
  return buf;
}

void free_dict_buf(char *dict_buf)
{
  free(dict_buf);
}

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void help() {
  puts("Arg: Help\n");
}

void version() {
  puts("Arg: Version\n");
}

void list(char* list) {
  printf("Arg: List has value: '%s'\n", list);
}

void value(char* val) {
  printf("Arg: Value is '%s'\n", val);
}


int main(int argc, char **argv) {
  bool help_flag = true;
  bool list_flag = true;
  bool version_flag = true;
  bool value_flag = true;

  while (1) {
    int index = 0;
    const char* short_options = "hvl::V:";
    const struct option long_options[] = {
        {"help",    no_argument,       0, 'h'},
        {"version", no_argument,       0, 'v'},
        {"list",    optional_argument, 0, 'l'},
        {"value",   required_argument, 0, 'V'},
        {0, 0, 0, 0}
    };

    int c;
    c = getopt_long(argc, argv, short_options, long_options, &index);

    if (c == -1) break;

    switch (c) {
      case 'h':
        if (help_flag) {
          help();
          help_flag = false;
        }
        break;
      case 'l':
        if (list_flag) {
          list(optarg);
          list_flag = false;
        }
        break;
      case 'v':
        if (version_flag) {
          version();
          version_flag = false;
        }
        break;
      case 'V':
        if (value_flag) {
          value(optarg);
          value_flag = false;
        }
        break;

      default:
        printf("this command is not supported\n", c);
    }
  }

  if (optind < argc) {
    printf("not defined options for args: ");
    while (optind < argc) {
      printf("%s ", argv[optind++]);
    }
    printf("\n");
  }
  exit(0);
}

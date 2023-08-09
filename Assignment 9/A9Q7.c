#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{

    struct passwd *pw = getpwuid(getuid());

    const char *homedir = pw->pw_dir;

    printf("Login user is : %s\n",pw->pw_name);
    printf("Home directory: %s\n",pw->pw_dir);

    return 0;
}


char auth_attempt(const char *, const char *);

int main(char c, char **v)
{
  char C = auth_attempt(v[1], v[2]);
  printf("Auth(%s, %s) = %d\n", v[1], v[2], (int)C);
  return 0;

}

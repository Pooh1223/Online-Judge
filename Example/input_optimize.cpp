template<class T>
bool input(T& ___){
  T _=0,__=1; char tc;
  do
  {
    tc=getchar();
    if(tc==EOF) return false;
  }while((tc<'0'||tc>'9')&&tc!='-');
  if(tc=='-') tc=getchar(),__=-1;
  while(tc>='0'&&tc<='9') _=_*10+(tc-'0'),tc=getchar();
  ___=_*__;
  return true;
}
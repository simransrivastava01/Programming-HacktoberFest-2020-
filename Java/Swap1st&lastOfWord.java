class Result
{
  static String swapFirstLastChar(String str)
  {
    String st="";
    String w[]=str.split(" ");
    for(String s:w)
    {
      int l=s.length();
      char s1=s.charAt(0);
      char s2=s.charAt(l-1);
      st=st+s2;
      for(int i=1;i<l-1;i++)
      {
        st=st+s.charAt(i);
      }
      st=st+s1;
      st=st+" ";
    }
    st=st.trim();
return st;
  }
}
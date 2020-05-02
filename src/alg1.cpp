std::string infx2pstfx(std::string inf){
     TStack<char> stack1;
     std::string result;

    int len = inf.length();
    for (int z = 0; z < len; z++) {
        if ('0' <= inf[z] && inf[z] <= '9') { 
            result += inf[z]; 
        }
         else if (inf[z] == '(')
            stack1.push(inf[z]);
           else if ((inf[z] == '+' || inf[z] == '-') && (stack1.get() != '*') && (stack1.get() != '/') && (stack1.get() != '+') && (stack1.get() != '-'))
               stack1.push(inf[z]);
              else if ((inf[z] == '*')  && ((stack1.get() != '*') && (stack1.get() != '/') || (stack1.get() == '+') || (stack1.get() == '-')))
                 stack1.push(inf[z]);
                  else if ( (inf[z] == '/') && ((stack1.get() != '*') && (stack1.get() != '/') || (stack1.get() == '+') || (stack1.get() == '-'))  )
                    stack1.push(inf[z]);
        else if (inf[z] == ')'){
            while (stack1.get() != '(') {
                result += stack1.get();
                  stack1.pop();
            }
          stack1.pop();
        }
        else{
            if (inf[z] == '+' || inf[z] == '-'){
                while ((stack1.get() != '(') && (!stack1.isEmpty())){
                    result += stack1.get();
                      stack1.pop();
                }
              stack1.push(inf[z]);
            }
      if (inf[z] == '*' || inf[z] == '/') {
          while ((stack1.get() == '*' || stack1.get() == '/') && (!stack1.isEmpty())) {
               result += stack1.get();
                      stack1.pop();
                }
                stack1.push(inf[z]);
            }
        }
    }
    while (!stack1.isEmpty()) {
        result += stack1.get();
        stack1.pop();
    }
    inf = result;
    return inf;
}

int eval(std::string pst){
    TStack<int> stack2;
    int len = pst.length();
    for (int z = 0; z < len; z++) {
      if ('0' <= pst[z] && pst[z] <= '9') {
         int x = pst[z] - '0';
            stack2.push(x);
        }
   if (pst[z] == '+') {
     int n = stack2.get();  stack2.pop();
       int m = stack2.get();  stack2.pop();
         int h = m + n;  stack2.push(h);
        }
    if (pst[z] == '-') {
      int n = stack2.get();  stack2.pop();
        int m = stack2.get();  stack2.pop();
          int h = m - n;  stack2.push(h);
        }
    if (pst[z] == '*') {
      int n = stack2.get();  stack2.pop();
        int m = stack2.get();  stack2.pop();
          int h = m * n;  stack2.push(h);
        }
    if (pst[i] == '/') {
      int n = stack2.get();  stack2.pop();
        int m = stack2.get();  stack2.pop();
          int h = m / n;  stack2.push(h);
        }
    }
    int result = stack2.get();  stack2.pop();
 return result;
}

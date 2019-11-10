conscell S_Expression(){
  conscell local, temp;
  if (token == "(") {
    local = new node;
    getToken();
    local -> car = S_Expression();
    temp = local;
    while (token != ")") {
      temp -> cdr = new node;
      temp = temp -> cdr
      temp -> car = S_Expression();
    }
    temp -> cdr = NULL;
  } else {
    // When looking at the symbol; insert of data in conscell
  }
}

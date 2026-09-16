
void worktree_cleanup(long *param_1)

{
  long lVar1;
  
  if (*param_1 != 0) {
    (*(code *)&DAT_04732840)(param_1[1],*param_1,1);
  }
  if (param_1[3] != 0) {
    (*(code *)&DAT_04732840)(param_1[4],param_1[3],1);
  }
  lVar1 = param_1[6];
  if (lVar1 != -2) {
    if ((lVar1 != -1) && (lVar1 != 0)) {
      (*(code *)&DAT_04732840)(param_1[7],lVar1,1);
    }
    lVar1 = param_1[9];
    if ((lVar1 != -1) && (lVar1 != 0)) {
      (*(code *)&DAT_04732840)(param_1[10],lVar1,1);
      return;
    }
  }
  return;
}



bool approval_decision_apply(long param_1,long param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)&DAT_120cae9d)(*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_2 + 8));
  if ((iVar1 == 0) && (*(long *)(param_1 + 0x28) == *(long *)(param_2 + 0x28))) {
    iVar1 = (*(code *)&DAT_120cae9d)
                      (*(undefined8 *)(param_1 + 0x20),*(undefined8 *)(param_2 + 0x20));
    return iVar1 == 0;
  }
  return false;
}



void verdict4_followup(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x10);
  if (lVar2 != 0) {
    lVar1 = *(long *)(param_1 + 8);
    do {
      func_0x07ae7e60(lVar1);
      lVar1 = lVar1 + 0x110;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
  }
  return;
}


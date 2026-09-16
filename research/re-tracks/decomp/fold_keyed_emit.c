
void fold_keyed_emit(undefined8 param_1,ulong param_2)

{
  code *pcVar1;
  long lVar2;
  ulong uStack_38;
  long lStack_30;
  ulong uStack_28;
  
  if ((param_2 & 1) == 0) {
    (*(code *)&DAT_12089060)(&uStack_38,param_1,param_2);
  }
  else {
    param_2 = param_2 >> 1;
    uStack_38 = param_2;
    uStack_28 = param_2;
    if (param_2 == 0) {
      lStack_30 = 1;
    }
    else {
      (*(code *)&DAT_04732870)();
      lVar2 = (*(code *)&DAT_04732830)(param_2,1);
      if (lVar2 == 0) {
        (*(code *)&DAT_1208422d)(1,param_2);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      (*(code *)&DAT_120cba68)(lVar2,param_1,param_2);
      lStack_30 = lVar2;
    }
  }
  (*(code *)&DAT_0ff4dea0)(&uStack_38);
  return;
}


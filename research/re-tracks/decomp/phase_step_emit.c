
void phase_step_emit(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined1 uVar2;
  long lStack_40;
  long lStack_38;
  long lStack_30;
  
  uVar2 = param_2 == 0;
  if (-1 < param_2) goto code_r0x06a900b6;
  uVar2 = true;
  uVar1 = 0;
  while( true ) {
    param_1 = uVar1;
    (*(code *)&DAT_1208422d)(param_1,param_2);
code_r0x06a900b6:
    if ((bool)uVar2) break;
    (*(code *)&DAT_04732870)();
    lStack_38 = (*(code *)&DAT_04732830)(param_2,1);
    uVar2 = lStack_38 == 0;
    uVar1 = 1;
    if (!(bool)uVar2) {
      (*(code *)&DAT_120cba68)(lStack_38,param_1,param_2);
code_r0x06a900f4:
      lStack_40 = param_2;
      lStack_30 = param_2;
      (*(code *)&DAT_0ff4dea0)(&lStack_40);
      return;
    }
  }
  lStack_38 = 1;
  goto code_r0x06a900f4;
}


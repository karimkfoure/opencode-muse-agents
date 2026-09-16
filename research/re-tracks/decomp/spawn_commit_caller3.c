
undefined1  [16] spawn_commit_caller3(undefined8 param_1)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  undefined1 auStack_1090 [112];
  undefined8 uStack_1020;
  undefined1 auStack_c70 [1040];
  long lStack_860;
  long *plStack_858;
  long lStack_440;
  long lStack_438;
  undefined8 auStack_430 [130];
  
  uStack_1020 = 0;
  func_0x052e7150(&lStack_860,param_1,&UNK_006d3f7b,0x16,&UNK_12137f80,6);
  plVar2 = plStack_858;
  if (lStack_860 != -1) {
    (*(code *)&DAT_120cba68)(auStack_1090,&lStack_860,0x420);
    (*(code *)&DAT_0ecb3f40)(&lStack_440,auStack_1090);
    if (lStack_440 != -1) {
      (*(code *)&DAT_120cba68)(auStack_c70,auStack_430,0x410);
      (*(code *)&DAT_04732870)();
      plVar2 = (long *)(*(code *)&DAT_04732830)(0x420,8);
      if (plVar2 == (long *)0x0) {
        (*(code *)&DAT_12088f47)(8,0x420);
        pcVar1 = (code *)swi(3);
        auVar4 = (*pcVar1)();
        return auVar4;
      }
      *plVar2 = lStack_440;
      plVar2[1] = lStack_438;
      (*(code *)&DAT_120cba68)(plVar2 + 2,auStack_c70,0x410);
      uVar3 = 0;
      goto code_r0x06484269;
    }
    plVar2 = (long *)phase_step_emit(lStack_438,auStack_430[0]);
  }
  uVar3 = 1;
code_r0x06484269:
  auVar4._8_8_ = plVar2;
  auVar4._0_8_ = uVar3;
  return auVar4;
}


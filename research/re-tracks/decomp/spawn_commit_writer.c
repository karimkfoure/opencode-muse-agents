
undefined8 * spawn_commit_writer(undefined8 *param_1,undefined8 param_2)

{
  undefined1 auStack_c78 [1056];
  long lStack_858;
  undefined8 uStack_850;
  long lStack_438;
  undefined8 uStack_430;
  undefined8 uStack_428;
  
  func_0x052e7150(&lStack_858,param_2,&UNK_006d3f7b,0x16,&UNK_12137f80,6);
  if (lStack_858 != -1) {
    (*(code *)&DAT_120cba68)(auStack_c78,&lStack_858,0x420);
    (*(code *)&DAT_0ecb3f40)(&lStack_438,auStack_c78);
    if (lStack_438 != -1) {
      (*(code *)&DAT_120cba68)(param_1,&lStack_438,0x420);
      return param_1;
    }
    uStack_850 = phase_step_emit(uStack_430,uStack_428);
  }
  param_1[1] = uStack_850;
  *param_1 = 0xffffffffffffffff;
  return param_1;
}


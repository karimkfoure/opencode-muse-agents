
void tool_apply_slot(ulong *param_1,ulong param_2,ulong param_3,undefined8 param_4,ulong param_5)

{
  code *pcVar1;
  ulong uVar2;
  ulong extraout_RDX;
  ulong uVar3;
  int aiStack_30 [2];
  ulong uStack_28;
  undefined8 uStack_20;
  
  if (param_5 != 0) goto code_r0x0646221b;
  do {
    param_1 = (ulong *)0x0;
    (*(code *)&DAT_1208422d)();
    param_3 = extraout_RDX;
code_r0x0646221b:
  } while (CARRY8(param_3,param_2));
  uVar2 = *param_1 * 2;
  if (uVar2 < param_3 + param_2) {
    uVar2 = param_3 + param_2;
  }
  uVar3 = 8;
  if (param_5 != 1) {
    uVar3 = (ulong)(param_5 < 0x401) * 3 + 1;
  }
  if (uVar3 < uVar2) {
    uVar3 = uVar2;
  }
  func_0x064d5b40(aiStack_30,*param_1,param_1[1],uVar3,param_4);
  if (aiStack_30[0] != 1) {
    param_1[1] = uStack_28;
    *param_1 = uVar3;
    return;
  }
  (*(code *)&DAT_1208422d)(uStack_28,uStack_20);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


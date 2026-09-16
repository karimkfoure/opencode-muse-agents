
/* WARNING: Switch with 1 destination removed at 0x06b02162 */

undefined8 * approval_judge_callsite(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)

{
  byte *pbVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  undefined8 uVar5;
  ulong uVar6;
  long *in_FS_OFFSET;
  
  pbVar1 = (byte *)*param_2;
  lVar2 = param_2[1];
  lVar3 = *in_FS_OFFSET;
  if (*(char *)(lVar3 + -0x5c0) != '\x01') {
    if (*(char *)(lVar3 + -0x5c0) == '\x02') goto code_r0x06aff095;
    (*(code *)&DAT_12020b20)(lVar3 + -0x608,&UNK_05a0aa90);
    *(undefined1 *)(lVar3 + -0x5c0) = 1;
  }
  if ((*(char *)(lVar3 + -0x5c4) == '\x01') && (*(char *)(lVar3 + -0x5c3) == '\0')) {
    (*(code *)&DAT_0fe498b0)(param_3);
    *param_1 = 0xffffffffffffffff;
    return param_1;
  }
code_r0x06aff095:
  uVar6 = 0;
  uVar5 = 0;
  if ((*pbVar1 & 1) == 0) {
    cVar4 = (*(code *)&DAT_0fe24b30)(lVar2,param_3,&UNK_06b02096,0);
    uVar5 = 1;
    if (cVar4 == '\0') {
      *pbVar1 = *pbVar1 | 1;
      *param_1 = 3;
      return param_1;
    }
  }
  do {
    do {
      uVar6 = (ulong)((int)uVar6 + 1);
    } while ((*pbVar1 & 2) != 0);
    cVar4 = (*(code *)&DAT_0fe24b30)
                      (lVar2 + 0x48,param_3,&UNK_006c35d0 + *(int *)(&UNK_006c35d0 + uVar6 * 4),
                       uVar5);
    uVar5 = 1;
  } while (cVar4 != '\0');
  *pbVar1 = *pbVar1 | 2;
  *param_1 = 4;
  return param_1;
}


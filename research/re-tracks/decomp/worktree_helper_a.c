
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long worktree_helper_a(long *param_1,undefined1 (*param_2) [16],long param_3,undefined4 *param_4)

{
  byte bVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  char cStack_38;
  undefined7 uStack_37;
  long lStack_30;
  long lStack_28;
  long lStack_20;
  
  if (*param_1 != -2) {
    worktree_helper_b();
    return 0;
  }
  if ((param_3 != 0x1e) ||
     (*param_2 != _UNK_00213e40 || *(undefined1 (*) [16])(*param_2 + 0xe) != _UNK_002212f0)) {
    lVar2 = (*(code *)&DAT_0ff4ab00)();
    return lVar2;
  }
  (*(code *)&DAT_0ff4bb90)(&cStack_38,*param_4);
  if (cStack_38 == -1) {
    return lStack_30;
  }
  bVar1 = *(byte *)(param_1 + 1);
  if (bVar1 < 3) {
    if (bVar1 < 3) goto code_r0x06e1cf7e;
code_r0x06e1cf3a:
    func_0x07813660(param_1 + 2);
  }
  else {
    if (bVar1 == 3) {
      lVar2 = param_1[2];
      if (lVar2 == 0) goto code_r0x06e1cf7e;
      lVar4 = param_1[3];
      uVar3 = 1;
    }
    else {
      if (bVar1 != 4) {
        if (bVar1 == 0xff) goto code_r0x06e1cf7e;
        goto code_r0x06e1cf3a;
      }
      func_0x07c89080(param_1 + 2);
      if (param_1[2] == 0) goto code_r0x06e1cf7e;
      lVar4 = param_1[3];
      lVar2 = param_1[2] << 5;
      uVar3 = 8;
    }
    (*(code *)&DAT_04732840)(lVar4,lVar2,uVar3);
  }
code_r0x06e1cf7e:
  param_1[3] = lStack_28;
  param_1[4] = lStack_20;
  param_1[1] = CONCAT71(uStack_37,cStack_38);
  param_1[2] = lStack_30;
                    /* WARNING: Read-only address (ram,0x00213e40) is written */
                    /* WARNING: Read-only address (ram,0x002212f0) is written */
                    /* WARNING: Read-only address (ram,0x00213e40) is written */
                    /* WARNING: Read-only address (ram,0x002212f0) is written */
  return 0;
}


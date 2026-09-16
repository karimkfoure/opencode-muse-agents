
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * subagent_spawn_gate(undefined1 (*param_1) [16],long param_2,undefined8 param_3)

{
  ulong uVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  
  uVar1 = param_2 - 0xc;
  switch(uVar1) {
  case 0:
    if (*(int *)(*param_1 + 8) == 0x74696d69 && *(long *)*param_1 == 0x6c5f74756f6e6166) {
      return &UNK_006fce82;
    }
    goto code_r0x0759a4f4;
  case 1:
  case 3:
  case 4:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x13:
  case 0x15:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
                    /* WARNING: Read-only address (ram,0x00202020) is written */
                    /* WARNING: Read-only address (ram,0x002030a0) is written */
                    /* WARNING: Read-only address (ram,0x00204430) is written */
                    /* WARNING: Read-only address (ram,0x00208f10) is written */
                    /* WARNING: Read-only address (ram,0x00208f20) is written */
                    /* WARNING: Read-only address (ram,0x0020b0f0) is written */
                    /* WARNING: Read-only address (ram,0x0020b100) is written */
                    /* WARNING: Read-only address (ram,0x0020c370) is written */
                    /* WARNING: Read-only address (ram,0x00210b60) is written */
                    /* WARNING: Read-only address (ram,0x00211c40) is written */
                    /* WARNING: Read-only address (ram,0x00212ad0) is written */
                    /* WARNING: Read-only address (ram,0x0021bd90) is written */
                    /* WARNING: Read-only address (ram,0x0021ca10) is written */
                    /* WARNING: Read-only address (ram,0x0021cf00) is written */
                    /* WARNING: Read-only address (ram,0x0021cf10) is written */
                    /* WARNING: Read-only address (ram,0x0021f2d0) is written */
                    /* WARNING: Read-only address (ram,0x002227f0) is written */
                    /* WARNING: Read-only address (ram,0x002232e0) is written */
    return (undefined *)0x0;
  case 2:
    if (*(long *)(*param_1 + 6) == 0x65756575715f7974 && *(long *)*param_1 == 0x7974696361706163) {
      return &UNK_006fce97;
    }
    goto code_r0x0759a4f4;
  case 5:
    if (ZEXT116((byte)param_1[1][0]) == _UNK_002232e0 && *param_1 == _UNK_00202020) {
      return &UNK_006fcf91;
    }
    if (ZEXT116((byte)param_1[1][0]) == _UNK_002232e0 && *param_1 == _UNK_002030a0) {
      return &UNK_006fcf70;
    }
    break;
  case 6:
    if (ZEXT216(*(ushort *)param_1[1]) == _UNK_0021ca10 && *param_1 == _UNK_0021bd90) {
      return &UNK_006f93b1;
    }
    if (ZEXT216(*(ushort *)param_1[1]) == _UNK_0021ca10 && *param_1 == _UNK_002227f0) {
      return &UNK_006f93b1;
    }
    return (undefined *)0x0;
  case 7:
    if (*param_1 == _UNK_00210b60 && *(undefined1 (*) [16])(*param_1 + 3) == _UNK_0020b100) {
      return &UNK_006fcea9;
    }
    break;
  case 8:
    if (*param_1 == _UNK_00204430 && ZEXT416(*(uint *)param_1[1]) == _UNK_0021cf00) {
      return &UNK_006fcf25;
    }
    break;
  case 9:
    if (*param_1 == _UNK_0021cf10 && *(undefined1 (*) [16])(*param_1 + 5) == _UNK_00208f10) {
      return &UNK_006fcf48;
    }
    break;
  case 0xe:
    goto code_r0x0759a4fa;
  case 0x12:
    if (*param_1 == _UNK_00212ad0 && *(undefined1 (*) [16])(*param_1 + 0xe) == _UNK_00211c40) {
      return &UNK_006fce61;
    }
code_r0x0759a4f4:
    if (param_2 != 0x1a) {
      return (undefined *)0x0;
    }
code_r0x0759a4fa:
    if (*param_1 == _UNK_0021f2d0 && *(undefined1 (*) [16])(*param_1 + 10) == _UNK_0020b0f0) {
      return &UNK_006fce3d;
    }
    return (undefined *)0x0;
  case 0x14:
    if (*param_1 == _UNK_0020c370 && param_1[1] == _UNK_00208f20) {
      return &UNK_006fcfbd;
    }
    break;
  case 0x16:
    iVar2 = (*(code *)&DAT_120cae9d)(param_1,&UNK_006fcd4a,0x22);
    if (iVar2 == 0) {
      return &UNK_006fce3d;
    }
    iVar2 = (*(code *)&DAT_120cae9d)(param_1,&UNK_006fcdb7,0x22);
    param_3 = extraout_RDX;
    if (iVar2 == 0) {
      return &UNK_006fcef8;
    }
    break;
  case 0x1b:
    iVar2 = (*(code *)&DAT_120cae9d)(param_1,&UNK_006fcdd9,0x27);
    param_3 = extraout_RDX_00;
    if (iVar2 == 0) {
      return &UNK_006fcece;
    }
    break;
  default:
    goto code_r0x0759a534;
  }
  if ((uVar1 >> 1 | (ulong)((uVar1 & 1) != 0) << 0x3f) < 10) {
                    /* WARNING: Could not recover jumptable at 0x0759a46f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar3 = (undefined *)
             (*(code *)(&UNK_006f5b84 + *(int *)(&UNK_006f5b84 + (uVar1 >> 1) * 4)))
                       (param_1,param_2,param_3,&UNK_006f5b84,
                        &UNK_006f5b84 + *(int *)(&UNK_006f5b84 + (uVar1 >> 1) * 4));
    return puVar3;
  }
code_r0x0759a534:
  return (undefined *)0x0;
}


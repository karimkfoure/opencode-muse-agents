/* build_child_state_result_envelope @ 0a81b270 | undefined8 * build_child_state_result_envelope(undefined8 *param_1); */

undefined8 * build_child_state_result_envelope(undefined8 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  long lVar9;
  undefined4 *puVar10;
  undefined8 uVar11;
  undefined8 uStack_a0;
  undefined8 *puStack_98;
  undefined8 uStack_90;
  undefined1 uStack_88;
  undefined4 uStack_87;
  undefined4 uStack_83;
  undefined4 uStack_7f;
  undefined3 uStack_7b;
  undefined1 uStack_78;
  undefined7 uStack_77;
  undefined8 uStack_70;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  long lStack_38;
  
  uStack_a0 = 0;
  uStack_90 = 0;
  FUN_04732870();
  puVar10 = (undefined4 *)thunk_FUN_12003a40(5,1);
  if (puVar10 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_1208422d(1,5);
  }
  *(undefined1 *)(puVar10 + 1) = 0x66;
  *puVar10 = 0x4f656e6f;
  uStack_88 = 5;
  uStack_87 = 0;
  uStack_83._3_1_ = (byte)puVar10;
  uStack_83 = (uint)uStack_83._3_1_ << 0x18;
  uStack_7f = (undefined4)((ulong)puVar10 >> 8);
  uStack_7b = (undefined3)((ulong)puVar10 >> 0x28);
  _uStack_7b = CONCAT13(5,uStack_7b);
  uStack_77 = 0;
  uStack_48 = 0;
  uStack_40 = (undefined4 *)0x8;
  lStack_38 = 0;
  FUN_0a8945e0(&uStack_68,&DAT_002626b0,8);
  FUN_0a762a30(&uStack_68,&UNK_0096a6dd,0xb,&UNK_0096b051,0xf);
  uVar8 = uStack_50._4_4_;
  uVar7 = (undefined4)uStack_50;
  uVar6 = uStack_54;
  uVar5 = uStack_58;
  uVar4 = uStack_5c;
  uVar3 = uStack_60;
  uVar2 = uStack_64;
  uVar1 = uStack_68;
  FUN_0ff47cf0(&uStack_48);
  uStack_40[4] = uVar5;
  uStack_40[5] = uVar6;
  uStack_40[6] = uVar7;
  uStack_40[7] = uVar8;
  *uStack_40 = uVar1;
  uStack_40[1] = uVar2;
  uStack_40[2] = uVar3;
  uStack_40[3] = uVar4;
  lStack_38 = 1;
  FUN_0a8945e0(&uStack_68,&UNK_00265be8,8);
  FUN_0a762a30(&uStack_68,&UNK_0096a6dd,0xb,&UNK_0096b060,0xf);
  lVar9 = lStack_38;
  uVar8 = uStack_50._4_4_;
  uVar7 = (undefined4)uStack_50;
  uVar6 = uStack_54;
  uVar5 = uStack_58;
  uVar4 = uStack_5c;
  uVar3 = uStack_60;
  uVar2 = uStack_64;
  uVar1 = uStack_68;
  if (lStack_38 == uStack_48) {
    FUN_0ff47cf0(&uStack_48);
  }
  puVar10 = uStack_40 + lVar9 * 8 + 4;
  *puVar10 = uVar5;
  puVar10[1] = uVar6;
  puVar10[2] = uVar7;
  puVar10[3] = uVar8;
  puVar10 = uStack_40 + lVar9 * 8;
  *puVar10 = uVar1;
  puVar10[1] = uVar2;
  puVar10[2] = uVar3;
  puVar10[3] = uVar4;
  lStack_38 = lVar9 + 1;
  FUN_0a8945e0(&uStack_68,&UNK_0096b06f,7);
  FUN_0a762a30(&uStack_68,&UNK_0096a6dd,0xb,&UNK_0096b076,0xe);
  lVar9 = lStack_38;
  uVar8 = uStack_50._4_4_;
  uVar7 = (undefined4)uStack_50;
  uVar6 = uStack_54;
  uVar5 = uStack_58;
  uVar4 = uStack_5c;
  uVar3 = uStack_60;
  uVar2 = uStack_64;
  uVar1 = uStack_68;
  if (lStack_38 == uStack_48) {
    FUN_0ff47cf0(&uStack_48);
  }
  puVar10 = uStack_40 + lVar9 * 8 + 4;
  *puVar10 = uVar5;
  puVar10[1] = uVar6;
  puVar10[2] = uVar7;
  puVar10[3] = uVar8;
  puVar10 = uStack_40 + lVar9 * 8;
  *puVar10 = uVar1;
  puVar10[1] = uVar2;
  puVar10[2] = uVar3;
  puVar10[3] = uVar4;
  lStack_38 = lVar9 + 1;
  FUN_0a8945e0(&uStack_68,&UNK_0096b084,0xb);
  FUN_0a762a30(&uStack_68,&UNK_0096a6dd,0xb,&UNK_0096b08f,0x16);
  lVar9 = lStack_38;
  uVar8 = uStack_50._4_4_;
  uVar7 = (undefined4)uStack_50;
  uVar6 = uStack_54;
  uVar5 = uStack_58;
  uVar4 = uStack_5c;
  uVar3 = uStack_60;
  uVar2 = uStack_64;
  uVar1 = uStack_68;
  if (lStack_38 == uStack_48) {
    FUN_0ff47cf0(&uStack_48);
  }
  puVar10 = uStack_40 + lVar9 * 8 + 4;
  *puVar10 = uVar5;
  puVar10[1] = uVar6;
  puVar10[2] = uVar7;
  puVar10[3] = uVar8;
  puVar10 = uStack_40 + lVar9 * 8;
  *puVar10 = uVar1;
  puVar10[1] = uVar2;
  puVar10[2] = uVar3;
  puVar10[3] = uVar4;
  lStack_38 = lVar9 + 1;
  FUN_0a8945e0(&uStack_68,&UNK_0096b0a5,7);
  FUN_0a762a30(&uStack_68,&UNK_0096a6dd,0xb,&UNK_0096b0ac,0xe);
  lVar9 = lStack_38;
  uVar8 = uStack_50._4_4_;
  uVar7 = (undefined4)uStack_50;
  uVar6 = uStack_54;
  uVar5 = uStack_58;
  uVar4 = uStack_5c;
  uVar3 = uStack_60;
  uVar2 = uStack_64;
  uVar1 = uStack_68;
  if (lStack_38 == uStack_48) {
    FUN_0ff47cf0(&uStack_48);
  }
  puVar10 = uStack_40 + lVar9 * 8 + 4;
  *puVar10 = uVar5;
  puVar10[1] = uVar6;
  puVar10[2] = uVar7;
  puVar10[3] = uVar8;
  puVar10 = uStack_40 + lVar9 * 8;
  *puVar10 = uVar1;
  puVar10[1] = uVar2;
  puVar10[2] = uVar3;
  puVar10[3] = uVar4;
  lStack_38 = lVar9 + 1;
  FUN_0a8945e0(&uStack_68,&UNK_0096a71b,6);
  FUN_0a762a30(&uStack_68,&UNK_0096a6dd,0xb,&UNK_0096b0ba,0xd);
  lVar9 = lStack_38;
  uVar8 = uStack_50._4_4_;
  uVar7 = (undefined4)uStack_50;
  uVar6 = uStack_54;
  uVar5 = uStack_58;
  uVar4 = uStack_5c;
  uVar3 = uStack_60;
  uVar2 = uStack_64;
  uVar1 = uStack_68;
  if (lStack_38 == uStack_48) {
    FUN_0ff47cf0(&uStack_48);
  }
  puVar10 = uStack_40 + lVar9 * 8 + 4;
  *puVar10 = uVar5;
  puVar10[1] = uVar6;
  puVar10[2] = uVar7;
  puVar10[3] = uVar8;
  puVar10 = uStack_40 + lVar9 * 8;
  *puVar10 = uVar1;
  puVar10[1] = uVar2;
  puVar10[2] = uVar3;
  puVar10[3] = uVar4;
  lStack_38 = lVar9 + 1;
  FUN_0a8945e0(&uStack_68,&UNK_0096b0c7,0xf);
  FUN_0a762a30(&uStack_68,&UNK_0096a6dd,0xb,&UNK_0096b0d6,0x21);
  lVar9 = lStack_38;
  uVar8 = uStack_50._4_4_;
  uVar7 = (undefined4)uStack_50;
  uVar6 = uStack_54;
  uVar5 = uStack_58;
  uVar4 = uStack_5c;
  uVar3 = uStack_60;
  uVar2 = uStack_64;
  uVar1 = uStack_68;
  if (lStack_38 == uStack_48) {
    FUN_0ff47cf0(&uStack_48);
  }
  puVar10 = uStack_40 + lVar9 * 8 + 4;
  *puVar10 = uVar5;
  puVar10[1] = uVar6;
  puVar10[2] = uVar7;
  puVar10[3] = uVar8;
  puVar10 = uStack_40 + lVar9 * 8;
  *puVar10 = uVar1;
  puVar10[1] = uVar2;
  puVar10[2] = uVar3;
  puVar10[3] = uVar4;
  lStack_38 = lVar9 + 1;
  FUN_0a8945e0(&uStack_68,&UNK_0096b0f7,0x14);
  FUN_0a762a30(&uStack_68,&UNK_0096a6dd,0xb,&UNK_0096b10b,0x21);
  lVar9 = lStack_38;
  uVar2 = uStack_64;
  uVar1 = uStack_68;
  if (lStack_38 == uStack_48) {
    FUN_0ff47cf0(&uStack_48);
  }
  puVar10 = uStack_40 + lVar9 * 8 + 4;
  *puVar10 = uStack_58;
  puVar10[1] = uStack_54;
  puVar10[2] = (undefined4)uStack_50;
  puVar10[3] = uStack_50._4_4_;
  *(ulong *)(uStack_40 + lVar9 * 8) = CONCAT44(uVar2,uVar1);
  *(ulong *)((long)(uStack_40 + lVar9 * 8) + 8) = CONCAT44(uStack_5c,uStack_60);
  uStack_50 = lVar9 + 1;
  uStack_60 = (undefined4)uStack_48;
  uStack_5c = uStack_48._4_4_;
  uStack_58 = (undefined4)uStack_40;
  uStack_54 = uStack_40._4_4_;
  uStack_68 = CONCAT31(uStack_68._1_3_,4);
  FUN_0a82c010(&uStack_48,&uStack_a0,&uStack_88,&uStack_68);
  if ((byte)uStack_48 < 3) {
    if (2 < (byte)uStack_48) {
LAB_0a81b784:
      FUN_0a833220(&uStack_40);
    }
  }
  else if ((byte)uStack_48 == 3) {
    if (uStack_40 != (undefined4 *)0x0) {
      uVar11 = 1;
      puVar10 = uStack_40;
LAB_0a81b7c2:
      thunk_FUN_120b3329(lStack_38,puVar10,uVar11);
    }
  }
  else if ((byte)uStack_48 == 4) {
    FUN_0a779560(&uStack_40);
    if (uStack_40 != (undefined4 *)0x0) {
      uVar11 = 8;
      puVar10 = (undefined4 *)((long)uStack_40 << 5);
      goto LAB_0a81b7c2;
    }
  }
  else if ((byte)uStack_48 != 0xff) goto LAB_0a81b784;
  uStack_64._3_1_ = (undefined1)uStack_a0;
  uStack_60 = (undefined4)((ulong)uStack_a0 >> 8);
  uStack_5c._0_3_ = (undefined3)((ulong)uStack_a0 >> 0x28);
  uStack_5c._3_1_ = SUB81(puStack_98,0);
  uStack_58 = (undefined4)((ulong)puStack_98 >> 8);
  uStack_54._0_3_ = (undefined3)((ulong)puStack_98 >> 0x28);
  uStack_54._3_1_ = (undefined1)uStack_90;
  uStack_50._0_4_ = (undefined4)((ulong)uStack_90 >> 8);
  uStack_50._4_3_ = (undefined3)((ulong)uStack_90 >> 0x28);
  uStack_88 = 5;
  uStack_87 = uStack_68;
  uStack_83 = uStack_64;
  uStack_7f = uStack_60;
  _uStack_7b = CONCAT13(uStack_5c._3_1_,(undefined3)uStack_5c);
  uStack_77 = (undefined7)((ulong)puStack_98 >> 8);
  uStack_70 = uStack_90;
  FUN_0a762a30(&uStack_88,&UNK_0096a6dd,0xb,&UNK_0096b12c,0x85);
  FUN_04732870();
  puStack_98 = (undefined8 *)thunk_FUN_12003a40(0xe,1);
  if (puStack_98 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_1208422d(1,0xe);
  }
  *(undefined8 *)((long)puStack_98 + 6) = 0x7373656e6e65706f;
  *puStack_98 = 0x706f2d70736d2d78;
  uStack_a0 = 0xe;
  uStack_90 = 0xe;
  FUN_04732870();
  puVar10 = (undefined4 *)thunk_FUN_12003a40(4,1);
  if (puVar10 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_1208422d(1,4);
  }
  *puVar10 = 0x6e65706f;
  uStack_68 = CONCAT31(uStack_68._1_3_,3);
  uStack_60 = 4;
  uStack_5c = 0;
  uStack_58 = SUB84(puVar10,0);
  uStack_54 = (undefined4)((ulong)puVar10 >> 0x20);
  uStack_50._0_4_ = 4;
  uStack_50._4_4_ = 0;
  FUN_0a8a3bf0(&uStack_48,&uStack_88,&uStack_a0,&uStack_68);
  if ((byte)uStack_48 < 3) {
    if ((byte)uStack_48 < 3) goto LAB_0a81b92b;
LAB_0a81b8e7:
    FUN_0a833220(&uStack_40);
  }
  else {
    if ((byte)uStack_48 == 3) {
      if (uStack_40 == (undefined4 *)0x0) goto LAB_0a81b92b;
      uVar11 = 1;
      puVar10 = uStack_40;
    }
    else {
      if ((byte)uStack_48 != 4) {
        if ((byte)uStack_48 == 0xff) goto LAB_0a81b92b;
        goto LAB_0a81b8e7;
      }
      FUN_0a779560(&uStack_40);
      if (uStack_40 == (undefined4 *)0x0) goto LAB_0a81b92b;
      uVar11 = 8;
      puVar10 = (undefined4 *)((long)uStack_40 << 5);
    }
    thunk_FUN_120b3329(lStack_38,puVar10,uVar11);
  }
LAB_0a81b92b:
  param_1[2] = CONCAT71(uStack_77,uStack_78);
  param_1[3] = uStack_70;
  *param_1 = CONCAT35((undefined3)uStack_83,CONCAT41(uStack_87,uStack_88));
  param_1[1] = CONCAT35(uStack_7b,CONCAT41(uStack_7f,uStack_83._3_1_));
  return param_1;
}


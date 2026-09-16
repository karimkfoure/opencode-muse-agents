/* append_steering_intake_record @ 08e05950 | undefined1 *append_steering_intake_record(undefined1 *param_1,long param_2,long param_3,undefined8 param_4,undefined4 *param_5); */

undefined1 *
append_steering_intake_record
          (undefined1 *param_1,long param_2,long param_3,undefined8 param_4,undefined4 *param_5)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 uStack_60;
  undefined7 uStack_5f;
  undefined7 uStack_58;
  undefined4 uStack_51;
  undefined4 uStack_4d;
  uint uStack_49;
  undefined4 uStack_45;
  undefined1 uStack_41;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  if (*(char *)(param_2 + 0xef08) == '\x02') {
    FUN_04732870();
    puVar2 = (undefined4 *)thunk_FUN_12003a40(0x39,1);
    if (puVar2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_1208422d(1,0x39);
    }
    *(undefined8 *)((long)puVar2 + 0x29) = 0x7665206e6f697373;
    *(undefined8 *)((long)puVar2 + 0x31) = 0x6b6e697320746e65;
    *(undefined8 *)(puVar2 + 8) = 0x732061206465656e;
    *(undefined8 *)(puVar2 + 10) = 0x65206e6f69737365;
    *(undefined8 *)(puVar2 + 4) = 0x6320657269772067;
    *(undefined8 *)(puVar2 + 6) = 0x2073646e616d6d6f;
    *puVar2 = 0x61627573;
    puVar2[1] = 0x746e6567;
    puVar2[2] = 0x65747320;
    puVar2[3] = 0x6e697265;
    *param_1 = 0x26;
    *(undefined8 *)(param_1 + 8) = 0x39;
    *(undefined4 **)(param_1 + 0x10) = puVar2;
    *(undefined8 *)(param_1 + 0x18) = 0x39;
    FUN_08c15f30(param_4);
  }
  else {
    FUN_120846f0(&uStack_58,param_3);
    uStack_40 = *(undefined4 *)(param_3 + 0x18);
    uStack_3c = *(undefined4 *)(param_3 + 0x1c);
    uStack_38 = *(undefined4 *)(param_3 + 0x20);
    uStack_34 = *(undefined4 *)(param_3 + 0x24);
    FUN_0c972e40(&uStack_168,param_4);
    uStack_6c._1_3_ = (undefined3)param_5[1];
    uStack_6c = CONCAT31(uStack_6c._1_3_,(char)((uint)*param_5 >> 0x18));
    uStack_68._1_3_ = (undefined3)param_5[2];
    uStack_68 = CONCAT31(uStack_68._1_3_,(char)((uint)param_5[1] >> 0x18));
    uStack_64._1_3_ = (undefined3)param_5[3];
    uStack_64 = CONCAT31(uStack_64._1_3_,(char)((uint)param_5[2] >> 0x18));
    uStack_60 = (undefined1)((uint)param_5[3] >> 0x18);
    uStack_70 = CONCAT31((int3)*param_5,1);
    FUN_0c07e850(&uStack_e8,param_2 + 0xee18,&uStack_58,&uStack_168,&uStack_70);
    if ((char)uStack_e8 == -1) {
      uVar1 = 0xff;
    }
    else {
      uStack_f8 = uStack_78;
      uStack_108 = uStack_88;
      uStack_100 = uStack_80;
      uStack_118 = uStack_98;
      uStack_110 = uStack_90;
      uStack_128 = uStack_a8;
      uStack_120 = uStack_a0;
      uStack_138 = uStack_b8;
      uStack_134 = uStack_b4;
      uStack_130 = uStack_b0;
      uStack_12c = uStack_ac;
      uStack_148 = uStack_c8;
      uStack_144 = uStack_c4;
      uStack_140 = uStack_c0;
      uStack_13c = uStack_bc;
      uStack_158 = uStack_d8;
      uStack_154 = uStack_d4;
      uStack_150 = uStack_d0;
      uStack_14c = uStack_cc;
      uStack_168 = uStack_e8;
      uStack_164 = uStack_e4;
      uStack_160 = uStack_e0;
      uStack_15c = uStack_dc;
      uStack_58 = SUB87(&uStack_168,0);
      uStack_51._0_1_ = (undefined1)((ulong)&uStack_168 >> 0x38);
      uStack_51 = CONCAT31(0xa16c10,(undefined1)uStack_51);
      uStack_4d = 0xd;
      uStack_49 = uStack_49 & 0xffffff00;
      FUN_12089060(&uStack_70,&UNK_00321a0d,&uStack_58);
      uStack_51 = uStack_70;
      uStack_4d = uStack_6c;
      uStack_49 = uStack_68;
      uStack_45 = uStack_64;
      uStack_41 = uStack_60;
      uStack_40 = (undefined4)uStack_5f;
      uStack_3c._0_3_ = (undefined3)((uint7)uStack_5f >> 0x20);
      FUN_08c17340(&uStack_168);
      *(ulong *)(param_1 + 0x10) = CONCAT44(uStack_45,uStack_49);
      *(ulong *)(param_1 + 0x18) = CONCAT35((undefined3)uStack_3c,CONCAT41(uStack_40,uStack_41));
      *(ulong *)(param_1 + 1) = CONCAT17((undefined1)uStack_51,uStack_58);
      *(ulong *)(param_1 + 9) = CONCAT17((undefined1)uStack_49,CONCAT43(uStack_4d,uStack_51._1_3_));
      uVar1 = 0x26;
    }
    *param_1 = uVar1;
  }
  return param_1;
}



undefined8 * subagent_field_fold(undefined8 *param_1,long param_2)

{
  undefined *puVar1;
  undefined ***pppuVar2;
  undefined ***pppuVar3;
  long lVar4;
  undefined8 uVar5;
  undefined *unaff_R13;
  undefined8 *puVar6;
  bool bVar7;
  bool bVar8;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined1 auStack_140 [64];
  long lStack_100;
  byte bStack_f8;
  long lStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined *puStack_c8;
  undefined *puStack_c0;
  undefined8 uStack_b8;
  long lStack_b0;
  undefined *puStack_a8;
  undefined *puStack_a0;
  undefined8 uStack_98;
  undefined ***pppuStack_90;
  undefined *puStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined ***pppuStack_60;
  undefined ***pppuStack_58;
  undefined **ppuStack_50;
  undefined *puStack_48;
  undefined8 *puStack_40;
  undefined ***pppuStack_38;
  
  puVar1 = *(undefined **)(param_2 + 0x10);
  puStack_40 = param_1;
  (*(code *)&DAT_0ff44220)(auStack_140);
  func_0x0772a830(&pppuStack_90,auStack_140);
  if ((char)pppuStack_90 == '\0') {
    pppuStack_58 = (undefined ***)0xffffffffffffffff;
    pppuStack_38 = (undefined ***)0xffffffffffffffff;
    pppuStack_60 = (undefined ***)0xffffffffffffffff;
    unaff_R13 = puVar1;
    puStack_c8 = puVar1;
    do {
      puVar6 = puStack_40;
      pppuVar2 = pppuStack_60;
      switch((ulong)pppuStack_90 >> 8 & 0xff) {
      case 0:
        if (pppuStack_58 != (undefined ***)0xffffffffffffffff) {
          ppuStack_50 = (undefined **)&UNK_006d4447;
          puStack_48 = (undefined *)0x6;
          pppuStack_90 = &ppuStack_50;
          puStack_88 = &UNK_05b4ad00;
          lVar4 = func_0x06a8f9e0(&UNK_0029e67a,&pppuStack_90);
code_r0x06d8b6a5:
          puStack_40[1] = lVar4;
          *puStack_40 = 0xffffffffffffffff;
          goto code_r0x06d8b159;
        }
        func_0x077313a0(&pppuStack_90,auStack_140);
        if (pppuStack_90 == (undefined ***)0xffffffffffffffff) {
          puStack_40[1] = puStack_88;
          *puStack_40 = 0xffffffffffffffff;
          pppuStack_58 = (undefined ***)0xffffffffffffffff;
          goto code_r0x06d8b159;
        }
        pppuStack_58 = pppuStack_90;
        uStack_d8 = uStack_80;
        lStack_b0 = uStack_78;
        uStack_b8 = uStack_70;
        uStack_d0 = uStack_68;
        unaff_R13 = puStack_88;
        break;
      case 1:
        if (pppuStack_38 != (undefined ***)0xffffffffffffffff) {
          ppuStack_50 = (undefined **)&UNK_006d444d;
          puStack_48 = (undefined *)0x5;
          pppuStack_90 = &ppuStack_50;
          puStack_88 = &UNK_05b4ad00;
          uVar5 = func_0x06a8f9e0(&UNK_0029e67a,&pppuStack_90);
          puStack_40[1] = uVar5;
          *puStack_40 = 0xffffffffffffffff;
          bVar8 = true;
          bVar7 = true;
          pppuVar3 = pppuStack_38;
          goto code_r0x06d8b15f;
        }
        func_0x077312c0(&pppuStack_90,auStack_140);
        pppuStack_38 = pppuStack_90;
        if (pppuStack_90 == (undefined ***)0xffffffffffffffff) {
          puStack_40[1] = puStack_88;
          *puStack_40 = 0xffffffffffffffff;
          bVar8 = true;
          bVar7 = true;
          pppuVar3 = (undefined ***)0xffffffffffffffff;
          goto code_r0x06d8b15f;
        }
        uStack_158 = (undefined4)uStack_80;
        uStack_154 = uStack_80._4_4_;
        uStack_150 = (undefined4)uStack_78;
        uStack_14c = uStack_78._4_4_;
        puStack_a8 = puStack_88;
        break;
      case 2:
        if (pppuStack_60 != (undefined ***)0xffffffffffffffff) {
          ppuStack_50 = (undefined **)&UNK_0026c5cc;
          puStack_48 = (undefined *)0x4;
          pppuStack_90 = &ppuStack_50;
          puStack_88 = &UNK_05b4ad00;
          uVar5 = func_0x06a8f9e0(&UNK_0029e67a,&pppuStack_90);
          puStack_40[1] = uVar5;
          *puStack_40 = 0xffffffffffffffff;
          bVar7 = true;
          bVar8 = true;
          puVar6 = puStack_40;
          pppuVar3 = pppuStack_38;
          goto joined_r0x06d8b65e;
        }
        func_0x077312c0(&pppuStack_90,auStack_140);
        puStack_c0 = puStack_88;
        if (pppuStack_90 == (undefined ***)0xffffffffffffffff) {
          puStack_40[1] = puStack_88;
          *puStack_40 = 0xffffffffffffffff;
          bVar7 = true;
          bVar8 = true;
          pppuVar3 = pppuStack_38;
          puVar6 = puStack_40;
          goto code_r0x06d8b186;
        }
        uStack_168 = (undefined4)uStack_80;
        uStack_164 = uStack_80._4_4_;
        uStack_160 = (undefined4)uStack_78;
        uStack_15c = uStack_78._4_4_;
        pppuStack_60 = pppuStack_90;
        break;
      case 3:
        lVar4 = func_0x07731140(auStack_140);
        if (lVar4 != 0) goto code_r0x06d8b6a5;
        break;
      default:
        bVar7 = pppuStack_58 == (undefined ***)0xffffffffffffffff;
        if (bVar7) {
          puStack_a0 = &UNK_006d4447;
          uStack_98 = 6;
          ppuStack_50 = &puStack_a0;
          puStack_48 = &UNK_05b4ad00;
          uVar5 = func_0x06a8f9e0(&UNK_002950fd,&ppuStack_50);
          puStack_40[1] = uVar5;
          *puStack_40 = 0xffffffffffffffff;
          bVar8 = true;
          pppuVar3 = pppuStack_38;
          goto code_r0x06d8b15f;
        }
        pppuStack_90 = pppuStack_58;
        uStack_80 = uStack_d8;
        uStack_78 = lStack_b0;
        uStack_70 = uStack_b8;
        uStack_68 = uStack_d0;
        bVar8 = pppuStack_38 == (undefined ***)0xffffffffffffffff;
        puStack_88 = unaff_R13;
        if (bVar8) {
          puStack_a0 = &UNK_006d444d;
          uStack_98 = 5;
          ppuStack_50 = &puStack_a0;
          puStack_48 = &UNK_05b4ad00;
          uVar5 = func_0x06a8f9e0(&UNK_002950fd,&ppuStack_50);
          puVar6[1] = uVar5;
          *puVar6 = 0xffffffffffffffff;
        }
        else {
          if (pppuStack_60 != (undefined ***)0xffffffffffffffff) {
            puStack_40[0xc] = CONCAT44(uStack_164,uStack_168);
            puStack_40[0xd] = CONCAT44(uStack_15c,uStack_160);
            puStack_40[8] = CONCAT44(uStack_154,uStack_158);
            puStack_40[9] = CONCAT44(uStack_14c,uStack_150);
            *puStack_40 = pppuStack_58;
            puStack_40[1] = unaff_R13;
            puStack_40[2] = uStack_d8;
            puStack_40[3] = lStack_b0;
            puStack_40[4] = uStack_b8;
            puStack_40[5] = uStack_d0;
            puStack_40[6] = pppuStack_38;
            puStack_40[7] = puStack_a8;
            puStack_40[10] = pppuStack_60;
            puStack_40[0xb] = puStack_c0;
            uStack_1d8 = *puStack_40;
            uStack_1d0 = puStack_40[1];
            uStack_1c8 = puStack_40[2];
            uStack_1c0 = puStack_40[3];
            uStack_1b8 = puStack_40[4];
            uStack_1b0 = puStack_40[5];
            uStack_1a8 = puStack_40[6];
            uStack_1a0 = puStack_40[7];
            uStack_198 = puStack_40[8];
            uStack_190 = puStack_40[9];
            uStack_188 = puStack_40[10];
            uStack_180 = puStack_40[0xb];
            uStack_178 = *(undefined4 *)(puStack_40 + 0xc);
            uStack_174 = *(undefined4 *)((long)puStack_40 + 100);
            uStack_170 = *(undefined4 *)(puStack_40 + 0xd);
            uStack_16c = *(undefined4 *)((long)puStack_40 + 0x6c);
            if (lStack_100 != 0) {
              uVar5 = func_0x06b1d460(puStack_c8,&UNK_12138720,&UNK_12138280);
              puVar6[1] = uVar5;
              *puVar6 = 0xffffffffffffffff;
              func_0x06cf96b0(&uStack_1d8);
            }
            goto code_r0x06d8b1f0;
          }
          puStack_a0 = &UNK_0026c5cc;
          uStack_98 = 4;
          ppuStack_50 = &puStack_a0;
          puStack_48 = &UNK_05b4ad00;
          uVar5 = func_0x06a8f9e0(&UNK_002950fd,&ppuStack_50);
          puVar6[1] = uVar5;
          *puVar6 = 0xffffffffffffffff;
          if (pppuStack_38 != (undefined ***)0x0) {
            (*(code *)&DAT_04732840)(puStack_a8,pppuStack_38,1);
          }
        }
        func_0x06cf9730(&pppuStack_90);
        pppuVar3 = pppuStack_38;
        goto code_r0x06d8b15f;
      }
      func_0x0772a830(&pppuStack_90,auStack_140);
    } while ((char)pppuStack_90 == '\0');
  }
  else {
    pppuStack_60 = (undefined ***)0xffffffffffffffff;
    pppuStack_38 = (undefined ***)0xffffffffffffffff;
    pppuStack_58 = (undefined ***)0xffffffffffffffff;
  }
  puStack_40[1] = puStack_88;
  *puStack_40 = 0xffffffffffffffff;
code_r0x06d8b159:
  bVar8 = true;
  bVar7 = true;
  pppuVar3 = pppuStack_38;
code_r0x06d8b15f:
  puVar6 = puStack_40;
  pppuVar2 = pppuStack_60;
  if (pppuStack_60 != (undefined ***)0xffffffffffffffff) {
joined_r0x06d8b65e:
    puStack_40 = puVar6;
    if (pppuVar2 != (undefined ***)0x0) {
      (*(code *)&DAT_04732840)(puStack_c0,pppuVar2,1);
    }
  }
code_r0x06d8b186:
  if ((bool)(0 < (long)pppuVar3 & bVar8)) {
    (*(code *)&DAT_04732840)(puStack_a8,pppuVar3,1);
  }
  if ((bool)(pppuStack_58 != (undefined ***)0xffffffffffffffff & bVar7)) {
    if (pppuStack_58 != (undefined ***)0x0) {
      (*(code *)&DAT_04732840)(unaff_R13,pppuStack_58,1);
    }
    if (lStack_b0 != 0) {
      (*(code *)&DAT_04732840)(uStack_b8,lStack_b0,1);
    }
  }
code_r0x06d8b1f0:
  func_0x078b5420(auStack_140);
  if (bStack_f8 < 3) {
    if (bStack_f8 < 3) {
      return puVar6;
    }
code_r0x06d8b3bd:
    func_0x07813660(&lStack_f0);
  }
  else {
    if (bStack_f8 == 3) {
      if (lStack_f0 == 0) {
        return puVar6;
      }
      uVar5 = 1;
    }
    else {
      if (bStack_f8 != 4) {
        if (bStack_f8 == 0xff) {
          return puVar6;
        }
        goto code_r0x06d8b3bd;
      }
      func_0x07c89080(&lStack_f0);
      if (lStack_f0 == 0) {
        return puVar6;
      }
      lStack_f0 = lStack_f0 << 5;
      uVar5 = 8;
    }
    (*(code *)&DAT_04732840)(uStack_e8,lStack_f0,uVar5);
  }
  return puVar6;
}


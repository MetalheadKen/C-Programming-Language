#include "isim/work/inst__fetch__tb/inst__fetch__tb.h"
#include "isim/work/glbl/glbl.h"
static const char * HSimCopyRightNotice = "Copyright 2004-2005, Xilinx Inc. All rights reserved.";


#include "work/inst__fetch__tb/inst__fetch__tb.h"
static HSim__s6* IF0(HSim__s6 *Arch,const char* label,int nGenerics, 
va_list vap)
{
    HSim__s6 *blk = new workMinst__fetch__tb(label); 
    return blk;
}


#include "work/rom/rom.h"
static HSim__s6* IF1(HSim__s6 *Arch,const char* label,int nGenerics, 
va_list vap)
{
    HSim__s6 *blk = new workMrom(label); 
    return blk;
}


#include "work/pc__reg/pc__reg.h"
static HSim__s6* IF2(HSim__s6 *Arch,const char* label,int nGenerics, 
va_list vap)
{
    HSim__s6 *blk = new workMpc__reg(label); 
    return blk;
}


#include "work/inst__fetch/inst__fetch.h"
static HSim__s6* IF3(HSim__s6 *Arch,const char* label,int nGenerics, 
va_list vap)
{
    HSim__s6 *blk = new workMinst__fetch(label); 
    return blk;
}


#include "work/glbl/glbl.h"
static HSim__s6* IF4(HSim__s6 *Arch,const char* label,int nGenerics, 
va_list vap)
{
    HSim__s6 *blk = new workMglbl(label); 
    return blk;
}

class _top : public HSim__s6 {
public:
    _top() : HSim__s6(false, "_top", "_top", 0, 0, HSim::VerilogModule) {}
    HSimConfigDecl * topModuleInstantiate() {
        HSimConfigDecl * cfgvh = 0;
        cfgvh = new HSimConfigDecl("default");
        (*cfgvh).addVlogModule("inst_fetch_tb", (HSimInstFactoryPtr)IF0);
        (*cfgvh).addVlogModule("rom", (HSimInstFactoryPtr)IF1);
        (*cfgvh).addVlogModule("pc_reg", (HSimInstFactoryPtr)IF2);
        (*cfgvh).addVlogModule("inst_fetch", (HSimInstFactoryPtr)IF3);
        (*cfgvh).addVlogModule("glbl", (HSimInstFactoryPtr)IF4);
        HSim__s5 * topvl = 0;
        topvl = new workMinst__fetch__tb("inst_fetch_tb");
        topvl->moduleInstantiate(cfgvh);
        addChild(topvl);
        topvl = new workMglbl("glbl");
        topvl->moduleInstantiate(cfgvh);
        addChild(topvl);
        return cfgvh;
}
};

main(int argc, char **argv) {
  HSimDesign::initDesign();
  globalKernel->getOptions(argc,argv);
  HSim__s6 * _top_i = 0;
  try {
    HSimConfigDecl *cfg;
 _top_i = new _top();
  cfg =  _top_i->topModuleInstantiate();
    return globalKernel->runTcl(cfg, _top_i, "_top", argc, argv);
  }
  catch (HSimError& msg){
    try {
      globalKernel->error(msg.ErrMsg);
      return 1;
    }
    catch(...) {}
      return 1;
  }
  catch (...){
    globalKernel->fatalError();
    return 1;
  }
}

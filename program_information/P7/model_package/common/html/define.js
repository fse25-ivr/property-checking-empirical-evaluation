function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:39,type:"fcn"};this.def["main"] = {file: "ert_main_c.html",line:76,type:"fcn"};this.def["rtDW"] = {file: "model_c.html",line:50,type:"var"};this.def["rtU"] = {file: "model_c.html",line:53,type:"var"};this.def["rtY"] = {file: "model_c.html",line:56,type:"var"};this.def["rtM_"] = {file: "model_c.html",line:59,type:"var"};this.def["rtM"] = {file: "model_c.html",line:60,type:"var"};this.def["exit_internal_ON"] = {file: "model_c.html",line:68,type:"fcn"};this.def["ModeManager"] = {file: "model_c.html",line:83,type:"fcn"};this.def["enter_internal_ModeManager"] = {file: "model_c.html",line:275,type:"fcn"};this.def["model_step"] = {file: "model_c.html",line:405,type:"fcn"};this.def["model_initialize"] = {file: "model_c.html",line:543,type:"fcn"};this.def["RT_MODEL"] = {file: "model_h.html",line:40,type:"type"};this.def["CdRequestMode"] = {file: "model_h.html",line:53,type:"type"};this.def["RadioRequestMode"] = {file: "model_h.html",line:65,type:"type"};this.def["DW"] = {file: "model_h.html",line:84,type:"type"};this.def["ExtU"] = {file: "model_h.html",line:93,type:"type"};this.def["ExtY"] = {file: "model_h.html",line:101,type:"type"};this.def["int8_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};this.def["uint8_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};this.def["int16_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};this.def["uint16_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};this.def["int32_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};this.def["uint32_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};this.def["int64_T"] = {file: "rtwtypes_h.html",line:59,type:"type"};this.def["uint64_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};this.def["real32_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};this.def["real64_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};this.def["real_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};this.def["time_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};this.def["boolean_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};this.def["int_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};this.def["uint_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};this.def["ulong_T"] = {file: "rtwtypes_h.html",line:73,type:"type"};this.def["ulonglong_T"] = {file: "rtwtypes_h.html",line:74,type:"type"};this.def["char_T"] = {file: "rtwtypes_h.html",line:75,type:"type"};this.def["uchar_T"] = {file: "rtwtypes_h.html",line:76,type:"type"};this.def["byte_T"] = {file: "rtwtypes_h.html",line:77,type:"type"};this.def["pointer_T"] = {file: "rtwtypes_h.html",line:98,type:"type"};}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "/";
var isPC = false;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["model_c.html"] = "../model.c";
	this.html2Root["model_c.html"] = "model_c.html";
	this.html2SrcPath["model_h.html"] = "../model.h";
	this.html2Root["model_h.html"] = "model_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","model_c.html","model_h.html","rtwtypes_h.html"];

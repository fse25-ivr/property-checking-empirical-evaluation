function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "model"};
	this.sidHashMap["model"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "model:1"};
	this.sidHashMap["model:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/u"] = {sid: "model:11"};
	this.sidHashMap["model:11"] = {rtwname: "<Root>/u"};
	this.rtwnameHashMap["<Root>/Debouncer Logic Table"] = {sid: "model:1"};
	this.sidHashMap["model:1"] = {rtwname: "<Root>/Debouncer Logic Table"};
	this.rtwnameHashMap["<Root>/y"] = {sid: "model:12"};
	this.sidHashMap["model:12"] = {rtwname: "<Root>/y"};
	this.rtwnameHashMap["<S1>:14"] = {sid: "model:1:14"};
	this.sidHashMap["model:1:14"] = {rtwname: "<S1>:14"};
	this.rtwnameHashMap["<S1>:18"] = {sid: "model:1:18"};
	this.sidHashMap["model:1:18"] = {rtwname: "<S1>:18"};
	this.rtwnameHashMap["<S1>:13"] = {sid: "model:1:13"};
	this.sidHashMap["model:1:13"] = {rtwname: "<S1>:13"};
	this.rtwnameHashMap["<S1>:16"] = {sid: "model:1:16"};
	this.sidHashMap["model:1:16"] = {rtwname: "<S1>:16"};
	this.rtwnameHashMap["<S1>:20"] = {sid: "model:1:20"};
	this.sidHashMap["model:1:20"] = {rtwname: "<S1>:20"};
	this.rtwnameHashMap["<S1>:21"] = {sid: "model:1:21"};
	this.sidHashMap["model:1:21"] = {rtwname: "<S1>:21"};
	this.rtwnameHashMap["<S1>:22"] = {sid: "model:1:22"};
	this.sidHashMap["model:1:22"] = {rtwname: "<S1>:22"};
	this.rtwnameHashMap["<S1>:29"] = {sid: "model:1:29"};
	this.sidHashMap["model:1:29"] = {rtwname: "<S1>:29"};
	this.rtwnameHashMap["<S1>:28"] = {sid: "model:1:28"};
	this.sidHashMap["model:1:28"] = {rtwname: "<S1>:28"};
	this.rtwnameHashMap["<S1>:27"] = {sid: "model:1:27"};
	this.sidHashMap["model:1:27"] = {rtwname: "<S1>:27"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

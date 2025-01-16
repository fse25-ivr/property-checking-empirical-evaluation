function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "/Users/natppu/Documents/Research/TestGen/active_learn/benchmarks/StateFlow/ModelingASecuritySystemExample/MATLAB/model_ert_rtw/model.c",
	size: 27};
	 this.metricsArray.var["rtM_"] = {file: "/Users/natppu/Documents/Research/TestGen/active_learn/benchmarks/StateFlow/ModelingASecuritySystemExample/MATLAB/model_ert_rtw/model.c",
	size: 8};
	 this.metricsArray.var["rtU"] = {file: "/Users/natppu/Documents/Research/TestGen/active_learn/benchmarks/StateFlow/ModelingASecuritySystemExample/MATLAB/model_ert_rtw/model.c",
	size: 7};
	 this.metricsArray.var["rtY"] = {file: "/Users/natppu/Documents/Research/TestGen/active_learn/benchmarks/StateFlow/ModelingASecuritySystemExample/MATLAB/model_ert_rtw/model.c",
	size: 2};
	 this.metricsArray.fcn["model.c:Alarm"] = {file: "/Users/natppu/Documents/Research/TestGen/active_learn/benchmarks/StateFlow/ModelingASecuritySystemExample/MATLAB/model_ert_rtw/model.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["model_initialize"] = {file: "/Users/natppu/Documents/Research/TestGen/active_learn/benchmarks/StateFlow/ModelingASecuritySystemExample/MATLAB/model_ert_rtw/model.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["model_step"] = {file: "/Users/natppu/Documents/Research/TestGen/active_learn/benchmarks/StateFlow/ModelingASecuritySystemExample/MATLAB/model_ert_rtw/model.c",
	stack: 4,
	stackTotal: 4};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="model_metrics.html">Global Memory: 44(bytes) Maximum Stack: 4(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();

function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "/Users/natppu/Documents/Research/TestGen/active_learn/benchmarks/StateFlow/ModelingAnIntersectionOfTwo1wayStreetsUsingStateflowExample/MATLAB/Controller_ert_rtw/Controller.c",
	size: 8};
	 this.metricsArray.var["rtM_"] = {file: "/Users/natppu/Documents/Research/TestGen/active_learn/benchmarks/StateFlow/ModelingAnIntersectionOfTwo1wayStreetsUsingStateflowExample/MATLAB/Controller_ert_rtw/Controller.c",
	size: 8};
	 this.metricsArray.var["rtU"] = {file: "/Users/natppu/Documents/Research/TestGen/active_learn/benchmarks/StateFlow/ModelingAnIntersectionOfTwo1wayStreetsUsingStateflowExample/MATLAB/Controller_ert_rtw/Controller.c",
	size: 1};
	 this.metricsArray.var["rtY"] = {file: "/Users/natppu/Documents/Research/TestGen/active_learn/benchmarks/StateFlow/ModelingAnIntersectionOfTwo1wayStreetsUsingStateflowExample/MATLAB/Controller_ert_rtw/Controller.c",
	size: 4};
	 this.metricsArray.fcn["Controller_initialize"] = {file: "/Users/natppu/Documents/Research/TestGen/active_learn/benchmarks/StateFlow/ModelingAnIntersectionOfTwo1wayStreetsUsingStateflowExample/MATLAB/Controller_ert_rtw/Controller.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Controller_step"] = {file: "/Users/natppu/Documents/Research/TestGen/active_learn/benchmarks/StateFlow/ModelingAnIntersectionOfTwo1wayStreetsUsingStateflowExample/MATLAB/Controller_ert_rtw/Controller.c",
	stack: 0,
	stackTotal: 0};
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
	 this.codeMetricsSummary = '<a href="Controller_metrics.html">Global Memory: 21(bytes) Maximum Stack: 0(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();

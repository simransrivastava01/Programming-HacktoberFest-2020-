var DOB = "March 1, 1995";
var millisecondsBetweenDOBAnd1970 = Date.parse(DOB);
var millisecondsBetweenNowAnd1970 = Date.now();
var ageInMilliseconds = millisecondsBetweenNowAnd1970-millisecondsBetweenDOBAnd1970;

var milliseconds = ageInMilliseconds;
  var second = 1000;
  var minute = second*60;
  var hour = minute*60;
  var day = hour*24;
  var month = day*30; 
/*using 30 as base as months can have 28, 29, 30 or 31 days depending a month in a year it itself is a different piece of comuptation*/
  var year = day*365;

//let the age conversion begin
var years = Math.round(milliseconds/year);
var months = years*12;
var days = years*365;
var hours = Math.round(milliseconds/hour);
var seconds = Math.round(milliseconds/second);

  
function printResults(){
  var message = "Age in Years : "+years+
     "</br>Age in Months : "+months+
       "</br>Age in Days : "+days+
      "</br>Age in Hours : "+hours+
      "</br>Age in Seconds : "+seconds+
      "</br>Age in Milliseconds : "+milliseconds;
  document.getElementById('placeholder').innerHTML = message;
}

window.onload = printResults;



<style type="text/css">
.onoffswitch {
    position: relative; width: 62px;
    -webkit-user-select:none; -moz-user-select:none; -ms-user-select: none;
}
.onoffswitch-checkbox {
    position: absolute;
    opacity: 0;
    pointer-events: none;
}
.onoffswitch-label {
    display: block; overflow: hidden; cursor: pointer;
    border: 2px solid #6DACD6; border-radius: 20px;
}
.onoffswitch-inner {
    display: block; width: 200%; margin-left: -100%;
    transition: margin 0.3s ease-in 0s;
}
.onoffswitch-inner:before, .onoffswitch-inner:after {
    display: block; float: left; width: 50%; height: 19px; padding: 0; line-height: 19px;
    font-size: 10px; color: white; font-family: Trebuchet, Arial, sans-serif; font-weight: bold;
    box-sizing: border-box;
}
.onoffswitch-inner:before {
    content: "ON";
    padding-left: 2px;
    background-color: #34A7C1; 
	color: #FFFFFF;
}
.onoffswitch-inner:after {
    content: "OFF";
    padding-right: 2px;
    background-color: #EEEEEE; 
	color: #999999;
    text-align: right;
}
.onoffswitch-switch {
    display: block; width: 15px; 			margin: 2px;
    background: #FFCCCC;
    position: absolute; top: 0;   bottom: 0;
    right: 39px;
    border: 2px solid #6DACD6; border-radius: 20px;
    transition: all 0.3s ease-in 0s; 
}
.onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-inner {
    margin-left: 0;
}
.onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-switch {
    right: 0px; 
}
</style>

<html>
<body>
<div class="onoffswitch">
  <input type="checkbox" name="temp" class="onoffswitch-checkbox" id="a"  value="1">
  <label class="onoffswitch-label" for="a"> <span class="onoffswitch-inner"></span> <span class="onoffswitch-switch"></span> </label>
</div>
</body>
<html>
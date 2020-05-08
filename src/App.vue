<template>
  <div id="app">
    <div class="container">
      <div class="row">
        <div class="col-12 py-5">
          <h1 style="font-size: 5em; color: #488BC7;">How Today</h1>
        </div>
      </div>
      <div class="row">
        <div class="col-sm-4">
          <img src="./assets/Pressure.png" />
          <h5 class="data">Pressure<h1>{{todays.Pressure}} Pascal</h1></h5>
        </div>
        <div class="col-sm-4">
          <img src="./assets/altitude.png" />
          <h5 class="data">Altitude<h1>{{todays.Altitude}} ft.</h1></h5>
        </div>
        <div class="col-sm-4">
          <img src="./assets/Humidity.png" />
          <h5 style="text-aling: right" class="data">Humidity<h1>{{todays.Humidity}} %</h1></h5>
        </div>
        <div class="col-sm-4">
          <img src="./assets/temperature.png" />
          <h5 class="data">Temperature<h1>{{todays.Temperature}} Celcius</h1></h5>
        </div>
        <div class="col-sm-4">
          <img src="./assets/smoke.png"/>
          <h5 class="data">Smoke and Gas<h1>{{todays.Smoke_Gas}}</h1></h5>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import firebase from "firebase";

const config = {
  apiKey: "AIzaSyBpDYcA1gIgCvGxlTiu35wNxl9xhqusZBE",
  authDomain: "japanapi-b8124.firebaseapp.com",
  databaseURL: "https://japanapi-b8124.firebaseio.com",
  projectId: "japanapi-b8124",
  storageBucket: "japanapi-b8124.appspot.com",
  messagingSenderId: "220003021341"
};

firebase.initializeApp(config);

var database = firebase.database();
var todayRef = database.ref("/today");
console.log(todayRef);

export default {
  name: "app",
  data() {
    return {
      todays: {}
    };
  },
  mounted() {
    todayRef.on("value", snapshot => {
      this.todays = snapshot.val();
    });
  }
};
</script>
<style>
body{
  font-family: 'Baloo Bhaina 2', cursive;
}
img {
  margin-top: 1vh;
  border-radius: 4px;
  width: 60%;
}
.data{
  margin-top: 5vh;
}
</style>
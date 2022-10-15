// // Firebase Script
// var firebaseConfig = {
//     apiKey: "AIzaSyCDhmp4GIXdi5oBwpvqRdLz1g803hBP0cI",
//     authDomain: "smart-irrigation-system-1df0b.firebaseapp.com",
//     databaseURL: "https://smart-irrigation-system-1df0b-default-rtdb.firebaseio.com",
//     projectId: "smart-irrigation-system-1df0b",
//     storageBucket: "smart-irrigation-system-1df0b.appspot.com",
//     messagingSenderId: "970510922541",
//     appId: "1:970510922541:web:00eb219c17d8855354d9a4",
//     measurementId: "G-2E8HHV1FJ3"
//   };

//   // Initialize Firebase
//   const app = initializeApp(firebaseConfig);
//   const analytics = getAnalytics(app);

//   //Retrieving Data from Firebase
//   firebase.initializeApp(firebaseConfig);
//   var ref = firebase.database().ref();
//   ref.on("value",function(snapshot){
//       console.log(snapshot.val());
//   },function(error){
//       console.log("Error : "+ error.code);
//   })


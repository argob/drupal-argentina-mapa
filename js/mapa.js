function initMap() {

  var geocoder = new google.maps.Geocoder();

  var map = new google.maps.Map(document.getElementById('map'), {
    zoom: 16,
    center: myLatLng
  });

  var latlng = new google.maps.LatLng(myLatLng['lat'], myLatLng['lng']);

  geocoder.geocode({'latLng': latlng}, function(results, status) {
    if (status == google.maps.GeocoderStatus.OK) {
      if (results[0]) {
        map.fitBounds(results[0].geometry.viewport);
        marker.setMap(map);
        marker.setPosition(latlng);
        $('#direccionMapa').text(results[0].formatted_address);
      } else {
        console.log('No results found');
      }
    } else {
      console.log('Geocoder failed due to: ' + status);
    }
  });


  var marker = new google.maps.Marker({
    position: myLatLng,
    map: map,
    icon: {
      url: "https://www.argentina.gob.ar/sites/default/files/marker.png",
      size: new google.maps.Size(20, 20),
      origin: new google.maps.Point(0, 0),
      anchor: new google.maps.Point(10, 10)
    }
  });
}

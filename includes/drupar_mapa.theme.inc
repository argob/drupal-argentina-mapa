<?php

function drupar_mapa_theme($existing, $type, $theme, $path){
  return array(
    'drupar_mapa' => array(
      'path' => drupal_get_path('module', 'drupar_mapa') . '/templates/mapa',
      'template' => 'drupar_mapa',
    ),
  );
}




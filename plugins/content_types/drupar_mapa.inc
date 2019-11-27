<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Mapa'),
  'description' => t('Crea módulo de Mapa'),
  'category' => t('Drupar'),
  'render callback' => 'mapa_render',
  'admin info' => 'mapa_admin_info',
  'defaults' => array()
);


function mapa_render($subtype, $conf, $panel_args, $context = NULL){
  $block = new stdClass();
  $block->title = '';
  $nodo = node_load(arg(1));
  $keyMap = ''; //key de Gmaps

  $latitud = $nodo->field_latitud['und'][0]['value'];
  $longitud = $nodo->field_longitud['und'][0]['value'];

  drupal_add_js('var myLatLng = {lat: '.$latitud.' , lng: '.$longitud.'};', 'inline');
  drupal_add_js(drupal_get_path('module','drupar_mapa'). '/js/mapa.js');

  $block->content = theme('drupar_mapa',array('latitud' => $latitud ,'longitud' => $longitud, 'keyMap' => $keyMap));
  return $block;
}

/**
 * 'admin info' callback for panel pane.
 */
function mapa_admin_info($subtype, $conf, $contexts){
  {
    if (!empty($conf)) {
      $block = new stdClass;
      $block->title = $conf['override_title'] ? $conf['override_title_text'] : t('Mapa con ubicación en Google Maps');
      $block->content = t('Mapa con ubicación en Google Maps');
      return $block;
    }
  }
}
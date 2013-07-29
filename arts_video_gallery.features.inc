<?php
/**
 * @file
 * arts_video_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function arts_video_gallery_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function arts_video_gallery_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function arts_video_gallery_node_info() {
  $items = array(
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('Create a <em>Video</em> to add items to your video gallery.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

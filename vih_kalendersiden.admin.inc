<?php

/**
 * @file
 * VIH Kalendersiden admin settings.
 */

/**
 * Return the VIH Kalendersiden global settings form.
 */
function vih_kalendersiden_admin_settings() {
  $form['vih_kalendersiden_headline'] = array(
    '#type' => 'textfield',
    '#title' => t('Calendar headline'),
    '#required' => TRUE,
    '#default_value' => variable_get('vih_kalendersiden_headline', t('Vejle Idrætshøjskole')),
    '#description' => t('Headline to show on the calendar.'),
  );

  $form['vih_kalendersiden_logo_image'] = array(
    '#type' => 'managed_file',
    '#name' => 'vih_kalender_logo_image',
    '#title' => t('Logo'),
    '#size' => 40,
    '#description' => t('Do not upload an image too big'),
    '#upload_location' => 'public://kalendersiden/',
    '#default_value' => variable_get('vih_kalendersiden_logo_image', ''),
  );
  $form['#submit'][] = 'vih_kalendersiden_admin_file_submit';
  return system_settings_form($form);
}

/** 
 * Implements hook_settings_submit().
 */
function vih_kalendersiden_admin_file_submit($form, &$form_state) {
  if (isset($form_state['values']['vih_kalendersiden_logo_image'])) {
    $file = file_load($form_state['values']['vih_kalenderside_logo_image']);
    $file->status = FILE_STATUS_PERMANENT;
    if (file_save($file)) {
      drupal_set_message(t('The file has been saved.'));
    }
    else {
      drupal_set_message(t('The file has not been saved.'));
    }
    variable_set('vih_kalendersiden_logo_image', $file->fid);
    unset($form_state['values']['vih_kalendersiden_logo_image']);
  }
}
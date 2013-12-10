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

  return system_settings_form($form);
}

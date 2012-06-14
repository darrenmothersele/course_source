/**
* Provide the HTML to create the modal dialog.
*/
Drupal.theme.prototype.CourseSourceModal = function () {
  var html = '';
  html += '<div id="ctools-modal" class="popups-box">';
  html += '  <div class="ctools-modal-content ctools-sample-modal-content">';
  html += '          <div class="popups-container">';
  html += '            <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body"></div></div>';
  html += '          </div>';
  html += '  </div>';
  html += '</div>';
  return html;
}

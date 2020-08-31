;;; Some experiments

(defun toLily (line msg)
  (shell-command (format "./lily %d '%s'" line msg)))

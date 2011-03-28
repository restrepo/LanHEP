;; LanHEP mode --- Major mode for editing LanHEP input files

;;Copyright (C) 2011  Jose David Ruiz Alvarez

;; Author:      2011 Jose David Ruiz Alvarez
;; Maintainer:  jose@gfif.udea.edu.co
;; Created:     Feb 2011

;; Instalation (Ubuntu):
;; 1) System wide:
;;      sudo mkdir -p /usr/share/emacs/site-lisp/lhep
;;      sudo cp lhep.el /usr/share/emacs/site-lisp/lhep}
;;    In .emacs add the lines:
;;      (add-to-list 'load-path "/usr/share/emacs/site-lisp/lhep")
;;      (load "lhep")
;; 2) Local installation:
;;    Change /usr/share/emacs/site-lisp/ by $HOME/.emacs.d/site-lisp

;; lhep.el is free software: you can redistribute it and/or modify it
;; under the terms of the GNU General Public License as published by the Free
;; Software Foundation, either version 3 of the License, or (at your option)
;; any later version.
;;
;; python-mode.el is distributed in the hope that it will be useful, but
;; WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
;; or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
;; for more details.

(defvar lanhep-mode-hook nil)

(defvar lanhep-mode-map
  (let ((map (make-keymap)))
    (define-key map "\C-j" 'newline-and-indent)
    map)
  "Keymap for LanHEP major mode")

;;;###autoload
(add-to-list 'auto-mode-alist '("\\.mdl\\'" . lanhep-mode))

(defconst lanhep-font-lock-keywords
  (list
   '("\\<\\(AddHermConj\\|Check\\(?:BRST\\|Herm\\|Masses\\)\\|OrthMatrix\\|brst_transform\\|group\\|infinitesimal\\|keep_lets\\|l\\(?:et\\|term\\)\\|model\\|option\\|parameter\\|re\\(?:ad\\|pres\\)\\|special\\|transform\\|use\\)\\>" . font-lock-type-face)
   '("\\<\\(Sqrt2\\|Tau\\(?:pm\\|[123mp]\\)\\|c\\(?:3b\\|[38]\\)\\|de\\(?:lta(\\(?:\\(?:N\\|vector\\))\\)\\|riv\\)\\|eps\\(?:_c3b?\\|v\\)?\\|f_SU3\\|gamma5?\\|i\\|lambda\\|moment\\|tau\\(?:pm\\|[123mp]\\)\\)\\>" . font-lock-constant-face))
  "Declarations and Constants highlighting expressions for LanHEP mode")

(defconst lanhep-font-lock-keywords-1
  (append lanhep-font-lock-keywords
		  (list
		   '("\\<\\(do_\\(?:else\\(?:_if\\)?\\|if\\)\\|end_if\\|keys\\|quit\\|where\\)\\>" . font-lock-keyword-face)))
  "Flux Keywords to highlight in LanHEP mode")

(defconst lanhep-font-lock-keywords-2
  (append lanhep-font-lock-keywords-1
		  (list
		   '("\\<\\(Se\\(?:lectVertices\\|t\\(?:Angle\\|DefIndex\\|EM\\)\\)\\|a\\(?:cos\\|nti\\|sin\\|tan2?\\)\\|brsti\\|c\\(?:c\\(?:ghost\\)?\\|os\\)\\|down\\|external_func\\|fabs\\|g\\(?:host\\|sb\\)\\|pow\\|s\\(?:in\\|qrt\\)\\|tan\\|up\\|vev\\)\\>" . font-lock-function-name-face)))
  "Functions Keywords to highlight in LanHEP mode")

(defconst lanhep-font-lock-keywords-3
  (append lanhep-font-lock-keywords-2
		  (list
		   '("\\<\\(cspinor\\|s\\(?:calar\\|pinor3?\\)\\|\\(?:tens\\|vect\\)or\\)\\>" . font-lock-variable-name-face)
		   '("\\<\\(atexname\\|color\\|gauge\\|left\\|mass\\|pdg\\|right\\|texname\\|width\\)\\>" . font-lock-string-face)))
  "Particle Keywords to highlight in LanHEP mode")

(defvar lanhep-font-lock-keywords-0 lanhep-font-lock-keywords-3
  "Default highlighting expressions for LanHEP mode")

(defvar lanhep-mode-syntax-table
  (let ((table (make-syntax-table)))
    (modify-syntax-entry ?_ "w" table)
    (modify-syntax-entry ?% "<" table)
    (modify-syntax-entry ?\n ">" table)
  table))

(defun lanhep-mode ()
  "Major mode for editing LanHEP Language files"
  (interactive)
  (kill-all-local-variables)
  (set-syntax-table lanhep-mode-syntax-table)
  (use-local-map lanhep-mode-map)
  (set (make-local-variable 'font-lock-defaults) '(lanhep-font-lock-keywords-0))
  (setq major-mode 'lanhep-mode)
  (setq mode-name "LanHEP")
  (run-hooks 'lanhep-mode-hook))

(provide 'lanhep-mode)

;;(regexp-opt '("keys" "do_if" "model" "do_else" "do_else_if" "write" "quit" "end_if"
;;	     "option" "let" "use" "parameter" "sqrt" "OrthMatrix"
;;	     "vector" "gauge" "mass" "width" "color" "spinor" "left"
;;	     "right" "c3" "c8" "scalar" "lterm" "Sqrt2"))
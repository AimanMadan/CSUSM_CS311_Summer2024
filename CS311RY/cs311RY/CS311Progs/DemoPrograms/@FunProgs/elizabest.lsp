;; CS571 Yoshii - Eliza Example -- call (main) to start 
;; Eliza is a fake psycho therapist.
;; Look for ** to improve this.
;; ===================================================

;; data on patients
(setf (get 'mary 'age) 40)
(setf (get 'mary 'MS)  'married)
(setf (get 'mary 'kids) 3)
;; ** please add 2 other patient's data

;; The main loop
(defun main ()
  (prog  (L1 client ans count L2)

    (princ "Hi. My name is eliza. What is yours? ")
    (setq client (read))

    (cond ((not (get client 'age))
           (princ "You must be a brand new patient"))
          ( T
                (princ "Looking at my records you are ")
		(princ (get client 'age)) (princ " and ")
    		(princ (get client 'MS))
                (terpri)
                (princ "And you have ") 
                (princ (get client 'kids)) (princ " children.")))

    (terpri)
    (princ "So tell me how you are feeling today ")
    (princ '(enclose your answer in parentheses. NO COMMAS!))
    (terpri)
    (setq count 0) ;; counting the interactions
   
L1  (setq ans (read))  ;; patient answer is read
    (setq count (+ count 1)) (princ count)
    (if (eq count 10) (go L2))  ;; 10th interaction means go home
    
    (princ (response-to ans count)) ;; respond to the answer
    (terpri)
    (go L1)  ;; loop
	
L2 (princ '(Oops our time is up. See you next week))

  )
)           


;; the resonse-to function will use the following info
(setq key-words '(upset sad depressed angry worried tired feeling))
(setf (get 'tell 1) '(Tell me more about it))
(setf (get 'tell 2) '(Hmm.. describe it more))
(setf (get 'tell 3) '(Why do you think so?))
(setf (get 'tell 4) '(I see. And?))
(setf (get 'tell 5) '(How is that possible?))
(setf (get 'tell 6) '(Oh... ))
(setf (get 'tell 7) '(That is incredible))
(setf (get 'tell 8) '(Hmm.. Ok...))
(setf (get 'tell 9) '(That is difficult))
(setf (get 'tell 10) '(This is serious))


;; determine the response to the patient who said ans
;; count is the counter for the interaction
(defun response-to (ans count)
 (prog ()
  (setq ans (switchthem ans))
  (return
   (cond 
    ((member 'been (member 'have ans)) ;; "have been" in answer
       (append '(How long have you) (member 'been ans)))
    ((intersection ans key-words)     ;; found a key word
          (append '(Why are you) 
                   (list (car (intersection ans key-words)) '?) ))
    ( (member 'am (member 'I ans))     ;; "I am" in answer
      (append (subst 'are 'am (subst 'you 'i (subst 'me 'you ans)))
               '(..Is that right?)) )
    ( (member 'why ans) '(why do you think?))
    ( (member 'what ans) '(that is a difficult question)) 
    ( (member 'how ans) '(how?))
    ( (eq (car ans) 'because) '(I see. Interesting.)) 
     ;; ** add another condition here
    (T (get 'tell count)) ;; otherwise retrieve based on counter
   )	
  )
 )	
)

;; switches your, my, myself, yourself 
(defun switchthem (a)
(cond ((member 'your a) ( subst 'my 'your a))
      ((member 'my a) (subst 'your 'my a))
      ((member 'myself a) (subst 'yourself 'myself a))
      ((member 'yourself a) (subst 'myself 'yourself a))
      (t a))) 

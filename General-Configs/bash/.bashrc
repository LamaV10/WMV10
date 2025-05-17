# colorize bash
alias ls='ls --color=auto'

# bash complition case insensitiv
bind -s 'set completion-ignore-case on'

# show possebilites when tab is pressed
# bind 'TAB:menu-complete'
bind 'set show-all-if-ambiguous on'

eval "$(zoxide init bash)"

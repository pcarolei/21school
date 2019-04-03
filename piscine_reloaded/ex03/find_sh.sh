find . -type f \( -name "*.sh" \) | sed 's/\.sh/]/g' | cut -d ']' -f1 | sed 's/\.*\//[/g' | rev| cut -d '[' -f1 | rev

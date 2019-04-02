find . -type f \( -name "*.sh" \) | sed 's/\.sh/]/g' | cut -d ']' -f1 | sed 's/\.*\//[/g' | cut -d '[' -f2

import os
import subprocess

code_dir = "../"
title = "UERJ Codebook"
contents_file = "../contents.md"
codebook_model = "./model/codebook.tex"

def get_sections():
	sections = []
	section_name = None
	with open(contents_file, 'r') as f:
		for line in f:
			line = line.strip()
			if len(line) < 2: 
				continue
			if line[:2] == "**":
				section_name = line[2:-2]
				subsections = []
				if section_name is not None:
					sections.append((section_name, subsections))
			elif line[: 6] == "- [x] ":
				line = line[6: ]
				subsection_name = line[line.find('[') + 1 : line.find(']')]
				filename = line[line.find('(') + 1 : line.find(')')]

				if len(subsection_name) == 0:
					raise ValueError("Subsection parse error: %" % line)
				if section_name is None:
					raise ValueError("Subsection given without section")

				# run_test(filename)
				subsections.append((filename, subsection_name))
	return sections

def get_style(filename):
	ext = filename.lower().split('.')[-1]
	if ext in ['c', 'cc', 'cpp']:
		return 'cpp'
	elif ext in ['java']:
		return 'java'
	elif ext in ['py']:
		return 'py'
	elif ext in ['tex']:
		return 'tex'
	else:
		return 'txt'

# TODO: check if this is everything we need
def texify(s):
		#s = s.replace('\'', '\\\'')
		#s = s.replace('\"', '\\\"')
		return s

def get_tex(sections):
		tex = ''
		for (section_name, subsections) in sections:
				tex += '\\section{%s}\n' % texify(section_name)
				for (filename, subsection_name) in subsections:
						tex += '\\subsection{%s}\n' % texify(subsection_name)
						if get_style(filename) == 'tex':
							tex += '\\raggedbottom{\\input{%s}}\n' % (code_dir + filename)
						else:
							tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s/%s}\n' % (get_style(filename), code_dir, filename)
						tex += '\\hrulefill\n'
				tex += '\n'
		return tex

if __name__ == "__main__":
		sections = get_sections()
		tex = get_tex(sections)
		with open('contents.tex', 'w') as f:
				f.write(tex)
		latexmk_options = ["latexmk", "-pdf", codebook_model]
		subprocess.call(latexmk_options)
		os.system("mv codebook.pdf ../codebook.pdf")
		os.system("rm contents.tex")
		os.system("rm codebook.*")
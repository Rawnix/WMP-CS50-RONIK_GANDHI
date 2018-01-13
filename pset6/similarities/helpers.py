from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    # TODO
    alines = set(a.splitlines())
    blines = set(b.splitlines())
    commonLines = list(alines & blines)
    return commonLines


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    # asent = a.split('.')
    # bsent = b.split('.')
    # commonSent = []
    # for i in asent:
    #     if not i in commonSent and i in bsent:
    #         commonSent.append(i)
    commonSent = list(set(sent_tokenize(a, language='english')) & set(sent_tokenize(b, language='english')))
    return commonSent

def createSet(s, n):
    subs = set()
    for i in range(len(s)-n+1):
        subs.add(s[i:i+n])
    return subs

def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    # store the substrings of string a in a set:
    asubs = createSet(a, n)
    bsubs = createSet(b, n)
    commonSubs = list(asubs & bsubs)
    return commonSubs

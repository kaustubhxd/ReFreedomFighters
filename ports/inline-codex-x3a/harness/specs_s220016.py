"""Focused encoded-tree fixture for 0x49e140 ResourceCollection::Lookup."""
import struct

from pilot import S
from recruits_util import clear_hooks, rnd


def _pack_table(entries):
    """Encode sorted (name, child-or-None) entries in Lookup's packed form."""
    assert entries and len(entries) < 256
    names = [name.lower() for name, _ in entries]
    assert names == sorted(names)
    blobs = []
    for name, child in entries:
        tail = b'\0' if child is None else b'/' + _pack_table(child)
        blobs.append(name.encode('ascii') + tail)
    head = bytearray(1 + 4 * (len(blobs) - 1))
    head[0] = len(blobs)
    off = 0
    for i in range(1, len(blobs)):
        off += len(blobs[i - 1])
        struct.pack_into('<I', head, 1 + 4 * (i - 1), off)
    return bytes(head) + b''.join(blobs)


TREE = _pack_table([
    ('alpha', None),
    ('beta', None),
    ('gamma', None),
    ('root', [
        ('child', None),
        ('leaf', None),
        ('prefX', None),
    ]),
    ('zeta', None),
])


def _strnicmp(em, _result):
    """The cdecl `_strnicmp` import at 0x676408, with every call observable."""
    a, b, n = (em.arg32(i) for i in range(3))
    aa = em.rbytes(a, n)
    bb = em.rbytes(b, n)
    diff = 0
    for x, y in zip(aa, bb):
        lx = x + 32 if 65 <= x <= 90 else x
        ly = y + 32 if 65 <= y <= 90 else y
        if lx != ly or lx == 0:
            diff = lx - ly
            break
    em.calllog.append(('strnicmp', aa.hex(), bb.hex(), n))
    em.ret(eax=diff, argbytes=0)


def g49e140(c):
    """Cover binary lower-bound directions, case folding, hierarchy, and rejects."""
    clear_hooks(c)
    e = c.emu
    e.stub_import('_strnicmp', _strnicmp)
    mode = c.case % 10
    query = (
        b'alpha',          # first entry; binary lower-bound moves left
        b'BETA',           # case-insensitive exact match
        b'root/child',     # nested packed node
        b'//root/LEAF',    # leading slash collapse + nested case fold
        b'root/pref',      # prefix matches, terminal-byte guard rejects
        b'delta',          # absent interior key
        b'zeta',           # final entry; lower-bound moves right
        b'root/zzz',       # child-node miss
        b'',               # zero-width segment is not a valid terminal entry
        b'////',           # slash collapse reaches the zero-width path
    )[mode]
    data = rnd(c, len(TREE) + 32)
    name = rnd(c, len(query) + 33)
    e.wbytes(data, TREE + b'\xa5' * 32)
    e.wbytes(name, query + b'\0' + b'\x5a' * 32)
    return [rnd(c, 4), name, data]


S(0x49e140, 'ResourceCollection::Lookup packed path', 'thiscall', None,
  ret='eax', gen=g49e140,
  note='batch220016; packed case-insensitive path tree with import-call logging')

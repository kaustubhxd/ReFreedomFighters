"""specs_s200002.py - Sonnet-w2 batch 200002: SEH-framed vector-storage frees (0x54f870 stdcall(ptr, bytes) hooked, records the SEH chain it sees)
and 0x4e3f00 (0x4e6b40 thiscall hooked). Fake outer SEH records 0-2; fs:[0] compared after return."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, seh_record, seh_chain


def _vec(c, kind):
    """this object with begin/end pointers: begin may be 0, end may equal begin, differences odd or negative sometimes."""
    r = c.rng
    clear_hooks(c)
    seh_chain(c, r.choice([0, 1, 2]))
    hook_rec(c, 0x54f870, 2, ret=r.getrandbits(32), pop=8, side=seh_record(c, 2))
    o = rnd(c, 0x20)
    begin = r.choice([0, rnd(c, 16), r.getrandbits(32)])
    k = r.random()
    if k < 0.25:
        end = begin
    elif k < 0.4:
        end = (begin - r.randrange(1, 64)) & 0xffffffff
    else:
        end = (begin + r.randrange(0, 200)) & 0xffffffff
    c.emu.w32(o, begin)
    c.emu.w32(o + 8, end)
    return [o]


def g606c90(c): return _vec(c, 16)
def g42ba10(c): return _vec(c, 8)
def g5a5440(c): return _vec(c, 32)


def g4e3f00(c):
    clear_hooks(c)
    r = c.rng
    seh_chain(c, r.choice([0, 1, 2]))
    hook_rec(c, 0x4e6b40, 0, ret=r.getrandbits(32), this=True, side=seh_record(c, 2))
    return [rnd(c, 0x20)]


S(0x606c90, 'GUESS vector16 free', 'thiscall', None, ret='eax', gen=g606c90, note='batch200002')
S(0x42ba10, 'GUESS vector free bytes', 'thiscall', None, ret='eax', gen=g42ba10, note='batch200002')
S(0x5a5440, 'GUESS vector32 free', 'thiscall', None, ret='eax', gen=g5a5440, note='batch200002')
S(0x4e3f00, 'GUESS destroy member twice', 'thiscall', None, ret='eax', gen=g4e3f00, note='batch200002')

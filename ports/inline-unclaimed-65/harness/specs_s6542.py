"""specs_s6542.py - unclaimed-65 batch 42 (docs/20-unclaimed-65.md, claim 21): the 0x6e4928 pair-list match for GetButtonName (case 0). Copy of
group 2 (specs_s6536) with a pair list of one to three pairs; the entry key is drawn from the list keys half the time. Group 2 text follows.
 - unclaimed-65 batch 36 (docs/20-unclaimed-65.md, claim 21), group 2: ZInputActions::GetButtonName (stdcall, ret 8) with the
high word of code > 3 and [0x6e48bc] == 0: the bank search is skipped, edx = 0, and case 0 runs. The key (entry + 4, random among a few
values including 0xb8) goes through the empty 0x6e4928 list, and the render object (global 0x70039c) fills the name with slot 0xdc,
which the spec writes as a ZString (its first dword is a char pointer to a short string of length 0, 1 or 2). Length 1 takes the
append path (0x4cc6e0, 0x4cbe80, 0x4cbee0, 0x4cbec0). The real helpers run; the cookie check runs as the real code. Globals are set
in gen (the bank base at 0x6e48c0 is a 32-entry block of 12-byte entries)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    _flush_code(c)


def _cstr(c, s):
    a = c.emu.alloc(len(s) + 1, 4)
    c.emu.wbytes(a, s + b'\x00')
    return a


def _gen(c):
    # the bank table: no bank (0x6e48bc == 0) so the search is skipped; base at 0x6e48c0 (32 entries of 12 bytes)
    c.emu.w32(0x6e48bc, 0)
    # the pair list at 0x6e4928: 8-byte pairs (value at +0, key at +4), ended by a zero value. Half the cases use a key from the list.
    npairs = c.rng.randint(1, 3)
    pair_keys = []
    for j in range(npairs):
        k = c.rng.choice([0xb8, 0x10, 0x27, c.rng.getrandbits(32)])
        pair_keys.append(k)
        c.emu.w32(0x6e4928 + 8 * j, c.rng.choice([0xb8, 0x138, 0x5a, c.rng.getrandbits(32) | 1]))
        c.emu.w32(0x6e4928 + 8 * j + 4, k)
    c.emu.w32(0x6e4928 + 8 * npairs, 0)
    base = _rnd(c, 12 * 32)
    c.emu.w32(0x6e48c0, base)
    # the entry's key at +4 (0xb8 for a third of the cases, to exercise the 0x138 substitution when the flag is set)
    ks = [0xb8, 0x10, 0x27, c.rng.getrandbits(32)]
    idx = c.rng.randint(0, 31)
    key = c.rng.choice(ks + pair_keys)
    c.emu.w32(base + 12 * idx + 4, key)
    c.emu.w32(base + 12 * idx + 8, _cstr(c, b'LiteralX'))
    # the name the render object writes: length 0, 1 or 2
    n = c.rng.choice([0, 1, 1, 2])
    text = bytes([c.rng.randint(0x41, 0x5a) for _ in range(n)])

    def s_dc(e, r):
        # the ZString is filled with its characters inline (its first dword points at its own +4, as the release in 0x4cbee0 expects)
        e.calllog.append(('0xdc', e.reg('ecx'), (e.arg32(1),)))
        o = e.arg32(0)
        e.w32(o, (o + 4) & 0xffffffff)
        e.wbytes(o + 4, text + b'\x00')
        e.ret(eax=0, argbytes=8)

    rend_vt = c.emu.fake_vtable('gbn-render', 0x300, {0xdc: s_dc})
    rend = _rnd(c, 0x200)
    c.emu.w32(rend, rend_vt)
    c.emu.wbytes(rend + 0x6e, bytes([c.rng.choice([0, 1])]))   # the render flag byte (0x138 substitution when set)
    c.emu.w32(0x70039c, rend)
    out = _rnd(c, 0x80)
    # code: high word 4..0xffff (so edx = 0), low word = the index
    hi = c.rng.randint(4, 0xffff)
    return [out, (hi << 16) | idx]


S(0x439020, 'ZInputActions::GetButtonName (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen, setup=_setup,
  note='unclaimed-65 batch 42 (claim 21); pair-list match: group 2: search skipped, case 0 with length 0/1/2 names')

"""specs_s252.py - unclaimed area 25, slice 4: 0x438cc0 ZInputActions::GetActionMap(const char*).
Member at this+0x1214 is a logging vtable object: slot 0x4c writes the flag, slot 0x5c returns the next entry from a
per-case list and writes the flag (1 while entries remain). Entries have their name pointer at +8. IAT strcmp at 0x676414."""
from pilot import S
from anim_common import install_crt_str


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cstr(c, s):
    a = c.emu.alloc(len(s) + 1, 1)
    c.emu.wbytes(a, s.encode() + b'\x00')
    return a


def _getmap(c):
    install_crt_str(c)
    names = ['Move', 'Fire', 'Jump', 'Reload', 'Use']
    entries = []
    for i in range(c.rng.randint(0, 4)):
        e = _rnd(c, 0x20)
        nm = c.rng.choice(names) if c.rng.random() < 0.8 else None
        c.emu.w32(e + 8, _cstr(c, nm) if nm else 0)
        entries.append(e)
    want = c.rng.choice(names + ['Nope']) if c.rng.random() < 0.9 else None
    state = {'i': 0}

    def s5c(e, args):
        flag_p = args[0]
        if state['i'] < len(entries):
            ent = entries[state['i']]
            state['i'] += 1
            e.w32(flag_p, 1)
            return (ent, None)
        e.w32(flag_p, 0)
        return (0, None)

    def s4c(e, args):
        e.w32(args[0], 0)
        return (0, None)

    vt = c.emu.logging_vtable('Coll', 0x140, impl={0x4c: s4c, 0x5c: s5c}, argwords={0x4c: 1, 0x5c: 1})
    mem = _rnd(c, 0x20)
    c.emu.w32(mem, vt)
    self_ = _rnd(c, 0x1300)
    c.emu.w32(self_ + 0x1214, mem)
    c.emu.mu.ctl_flush_tb()
    return [self_, _cstr(c, want) if want else 0]


S(0x438cc0, 'ZInputActions::GetActionMap(const char*)', 'thiscall', None, ret='eax', gen=_getmap,
  note='batch252; list walk on the member vtable, IAT strcmp at 0x676414')

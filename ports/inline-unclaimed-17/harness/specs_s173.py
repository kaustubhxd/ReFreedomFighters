"""specs_s173.py - unclaimed area 17, slice 16: 0x4fc500 CMAINCAMERACONTROL::GetCamera (draft batch173).
Fakes per case: engine global 0x70039c -> heap engine whose +0x9b geom db is a logging vtable (slots 0x58, 0x4c);
the embedded object at this+0x98 (slots 0x14, 0x30); the object at this+0x44 (slot 0x12c); camera objects camA
(slot 0x128, 2 stack args) and camT (slot 0x128, 3 stack args), split by the parity of the geom argument.
ext_4fd800 is the original code (not stubbed)."""
from pilot import S

DBG = {}


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cam_struct(c):
    s = _rnd(c, 0x40)
    c.emu.w32(s + 0x23, c.rng.choice([0, 0x400000, 0x123456, c.rng.getrandbits(32)]))
    return s


def _getcamera(c):
    camA_s = _cam_struct(c)
    camT_s = _cam_struct(c)
    camA = _rnd(c, 0x40)
    camT = _rnd(c, 0x40)
    c.emu.w32(camA + 0xc, camA_s)
    c.emu.w32(camT + 0xc, camT_s)
    vtA = c.emu.logging_vtable('CamA', 0x140, argwords={0x128: 2, 0x12c: 3})
    vtT = c.emu.logging_vtable('CamT', 0x140, argwords={0x128: 3, 0x12c: 3})
    c.emu.w32(camA, vtA)
    c.emu.w32(camT, vtT)
    cams = {0: camA, 1: camT}

    def g58(e, args):
        return (cams[args[0] & 1] if args[0] % 5 >= 2 else 0, None)

    geom_vt = c.emu.logging_vtable('Geom', 0x140, impl={0x58: g58, 0x4c: lambda e, a: (c.rng.getrandbits(32), None)},
                                   argwords={0x58: 1, 0x4c: 2})
    geom = _rnd(c, 0xa0)
    c.emu.w32(geom, geom_vt)
    eng = _rnd(c, 0x200)
    c.emu.w32(eng + 0x9b, geom)
    c.emu.w32(0x70039c, eng)

    old74 = c.rng.choice([0x11, 0x23, 0x101])

    def emb30(e, a):
        # the list position equals this+0x74 in about half the cases (the no-change branch at 0x4fc645)
        return ((old74 if c.rng.random() < 0.5 else (c.rng.getrandbits(32) & ~1)), None)

    emb_vt = c.emu.logging_vtable('Emb', 0x40, impl={0x14: lambda e, a: (c.rng.choice([0, 1]), None),
                                                    0x30: emb30},
                                  argwords={0x30: 1})
    obj = _rnd(c, 0x200)
    c.emu.w32(obj + 0x98, emb_vt)
    o44_vt = c.emu.logging_vtable('O44', 0x140, argwords={0x12c: 3})
    o44 = _rnd(c, 0x80)
    c.emu.w32(o44, o44_vt)
    c.emu.w32(obj + 0x44, o44)
    # ext_4fd800's found-item branch calls slot 0x3c of the object at o44+0x18 (one stack argument)
    ob18_vt = c.emu.logging_vtable('Ob18', 0x140, argwords={0x3c: 1})
    ob18 = _rnd(c, 0x40)
    c.emu.w32(ob18, ob18_vt)
    c.emu.w32(o44 + 0x18, ob18)
    c.emu.w32(obj + 0x74, old74)   # odd: camT (3 stack args) at the t-call site
    if c.rng.random() < 0.6:
        # cursor list as ext_4fd800 walks it: item key at +0, next item at +0xc; the cursor is this node's +0x48
        node = _rnd(c, 0x80)
        n_items = c.rng.choice([1, 2, 3])
        items = [_rnd(c, 0x40) for _ in range(n_items)]
        for k, it in enumerate(items):
            c.emu.w32(it, (c.rng.getrandbits(31) // 5) * 5 if c.rng.random() < 0.7 else c.rng.getrandbits(32))   # key %5 == 0: geom returns 0, the walk moves on
            c.emu.w32(it + 0x8, 0)                                  # prev: none, so the unlink writes the owner's +0x48
            c.emu.w32(it + 0xc, items[k + 1] if k + 1 < n_items else 0)
            c.emu.w32(it + 0x10, node)                              # owner
        c.emu.w32(node + 0x48, items[0] if c.rng.random() < 0.85 else 0)
        c.emu.w32(obj + 0x84, node)
        DBG['node'] = node; DBG['items'] = list(items); DBG['obj'] = obj
    else:
        c.emu.w32(obj + 0x84, 0)
    v78 = c.rng.getrandbits(32) & ~1                        # even: camA (2 stack args) at the edi-call site
    while v78 % 5 < 2:                                      # geom must return an object here, or the original reads [0]
        v78 = c.rng.getrandbits(32) & ~1
    c.emu.w32(obj + 0x78, v78)
    c.emu.mu.ctl_flush_tb()
    return [obj]


S(0x4fc500, 'CMAINCAMERACONTROL::GetCamera (draft)', 'thiscall', None, ret='eax', gen=_getcamera,
  note='batch173 draft; geom and camera fakes, ext_4fd800 original')

"""specs_s90002.py - hard trial (fable) batch 90002: 0x43bc80 (action-map parser end-element handler). State E[0xc] 0..0xd and random;
name drawn from all 12 keywords plus near misses; ZStrings at E+0x10 and E+0x1c3 (char* at +0 to a heap buffer, sometimes empty); flags E[0xb5], E[0xb6];
E[8] object with slots 0x34/0x38. Hooked: error 0x43b9a0, ZString ctor/assign/dtor on the stack temp (recorded with stack markers), allocation
0x41e290 (returns a heap buffer made in the spec so the strcpy into it is compared), 0x43bbe0, /GS check. 0x4cc5f0/0x4cc1d0 (strlen/c_str) run real."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

KW = [b'Settings', b'ActionMap', b'Controls', b'Mapping', b'Group', b'Sequence', b'Mouse', b'Action', b'Key', b'NotKey', b'NotAction', b'Keys']
EXPECT = {0: [b'Settings'], 1: [b'ActionMap', b'Controls'], 2: [b'Mapping'], 3: [b'Group'], 4: [b'Mouse'], 5: [b'Action'],
          6: [b'Key', b'NotKey', b'Action', b'NotAction'], 0xb: [b'Sequence'], 0xc: [b'Keys']}
NEAR = [b'', b'settings', b'Keyz', b'Ke', b'ActionMa', b'NotActions', b'X', b'Mapping ', b'Controls\x01']


def _czstr(c, s):
    a = c.emu.alloc(len(s) + 1, 1)
    c.emu.wbytes(a, s + b'\0')
    return a


def _g43bc80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg('eax'))
    hook_rec(c, 0x43b9a0, 1, this=True)
    hook_rec(c, 0x4cbe80, 1, this='mark', ret=lambda em, k: em.reg('ecx'))
    hook_rec(c, 0x4cbee0, 1, this=True, stackmark=(0,), ret=lambda em, k: em.reg('ecx'))
    hook_rec(c, 0x4cbec0, 0, this='mark')
    buf = rnd(c, 0x100)
    hook_rec(c, 0x41e290, 1, pop=0, ret=buf)
    hook_rec(c, 0x43bbe0, 1, this=True)
    E = rnd(c, 0x260)
    st = r.choice(list(range(14)) + [0xd, 0x10, 0xffffffff, r.getrandbits(32)])
    if r.random() < 0.6 and st in EXPECT:   # the keyword this state expects, so every state's success path is common
        name = r.choice(EXPECT[st])
    else:
        name = r.choice(KW + KW + NEAR + [bytes(r.choice(b'ABCdefKey') for _ in range(r.randint(0, 6)))])
    e.w32(E + 0xc, st)
    e.w32(E + 8, obj(c, 0x20, {0x34: pystub(c, 1, this=True), 0x38: pystub(c, 1, this=True)}))
    s10 = r.choice([b'', b'jump', b'fire', b'use', bytes(r.randint(1, 255) for _ in range(r.randint(1, 40)))])
    s1c3 = r.choice([b'', b'A', b'group name', b'seq', bytes(r.randint(1, 255) for _ in range(r.randint(1, 0xf0)))])
    e.w32(E + 0x10, _czstr(c, s10))
    e.wbytes(E + 0x1c3, _czstr(c, s1c3).to_bytes(4, 'little'))
    e.wbytes(E + 0xb5, bytes([r.choice([0, 1, 1, 2, 0xff]), r.choice([0, 1, 1, 2, 0xff])]))
    return [E, _czstr(c, name)]


S(0x43bc80, 'GUESS action-map parser end element', 'thiscall', None, ret=None, gen=_g43bc80, note='batch90002')

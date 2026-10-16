"""specs_s66090.py - cascade s4 batch 66090: 0x5b37e0 (/GS: read the key bindings through the input service, choose the next usable slot, tell the owner object)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g5b37e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))
    keys = [r.getrandbits(32) | 1 for _ in range(10)]
    pressed = set(k for k in keys if r.random() < (0.12 if r.random() < 0.7 else 0.5))
    if r.random() < 0.4:
        pressed = {r.choice(keys)}
    if r.random() < 0.2:
        pressed = {keys[r.choice([8, 9])]}

    def h_key(em, rr):
        k = em.arg32(0)
        em.calllog.append(('key', k, em.arg32(1)))
        em.ret(eax=0x100 | (1 if k in pressed else 0), argbytes=8)
    inp = obj(c, 0x20, {0x2c: e.stub_fn('key', h_key)})
    sysobj_ = rnd(c, 0x2000)
    e.w32(sysobj_ + 0x1907, inp)
    e.w32(0x70039c, sysobj_)
    e._image_dirty = True
    me = rnd(c, 0x200)
    mode3 = r.random() < 0.5
    e.w32(me + 0x4d, 3 if mode3 else r.choice([0, 1, 2, 4]))
    e.wbytes(me + 0x17f, bytes([r.choice([0, 0, 0, 1, 2]), r.choice([0, 1, 1, 3])]))
    e.wbytes(me + 0x175, bytes([r.getrandbits(8)]))
    e.wbytes(me + 0x18a, bytes([r.choice([0, 0, 0, 1, 3, 4, 5, 8, 9, r.randrange(10)])]))
    e.wbytes(me + 0x189, bytes([r.getrandbits(8)]))
    e.wbytes(me + 0x1a3, bytes([0 if r.random() < 0.85 else 1]))
    for i, k in enumerate(keys):
        e.w32(me + 0xf3 + 4 * i, k)
    # the owner object (this + 0x5f): flags, slots 0x3dc and 0x4dc
    owner = obj(c, 0x900, {0x3dc: pystub(c, 0, this=True, pop=0),
                           0x4dc: pystub(c, 2, this=True, pop=8)}, nslots=0x4e0 // 4)
    e.w32(owner + 0x836, 0 if r.random() < 0.85 else r.getrandbits(32))
    e.w32(owner + 0x832, 0 if r.random() < 0.85 else r.getrandbits(32))
    e.w32(me + 0x5f, owner)
    # the second object (this + 0x5b): slot 0x90, field 0x1d0f -> object passed to 0x596710
    other = obj(c, 0x1d20, {0x90: pystub(c, 0, this=True, pop=0)}, nslots=0x94 // 4)
    third = rnd(c, 0x40)
    e.w32(other + 0x1d0f, third)
    e.w32(me + 0x5b, other)
    buf = bytearray(0x74)
    for off in range(0, 0x70, 4):
        buf[off:off + 4] = (0 if r.random() < 0.45 else r.getrandbits(32)).to_bytes(4, 'little')
    for off in (0x35, 0x39, 0x3d, 0x29, 0x31, 0x25, 0x2d, 0x41):
        buf[off:off + 4] = (0 if r.random() < 0.45 else r.getrandbits(32) | 1).to_bytes(4, 'little')
    buf[4:8] = (0 if r.random() < 0.5 else r.getrandbits(32)).to_bytes(4, 'little')
    buf[0xc:0x10] = (0 if r.random() < 0.5 else r.getrandbits(32)).to_bytes(4, 'little')

    shape = r.random()
    if shape < 0.25:                      # every entry zero: the search loop gives up after ten tries
        for off in (0x35, 0x39, 0x3d, 0x29, 0x31, 0x25, 0x2d, 0x41):
            buf[off:off + 4] = bytes(4)
    elif shape < 0.45:                    # only entries 4 and 5 (offsets 0x29 and 0x31 -> indices 4 and 5), guarded by buf[4] / buf[0xc]
        for off in (0x35, 0x39, 0x3d, 0x2d, 0x41, 0x25, 0x29, 0x31):
            buf[off:off + 4] = bytes(4)
        buf[4:8] = (0 if r.random() < 0.5 else 7).to_bytes(4, 'little')
        buf[0xc:0x10] = (0 if r.random() < 0.5 else 9).to_bytes(4, 'little')
        for off in (0x29, 0x31):
            buf[off:off + 4] = (0 if r.random() < 0.3 else 5).to_bytes(4, 'little')

    def h596710(em, rr):                  # thiscall(ecx = third, buffer) ret 4: fills the caller's 0x74-byte buffer
        em.calllog.append(('h596710', em.reg('ecx')))
        em.wbytes(em.arg32(0), bytes(buf))
        em.ret(eax=0, argbytes=4)
    e.hook(0x596710, h596710)
    match = r.random() < 0.6

    def h591b20(em, rr):                  # thiscall(ecx = owner) returns the current selection
        em.calllog.append(('h591b20', em.reg('ecx')))
        cur = em.rbytes(me + 0x18a, 1)[0]
        em.ret(eax=(cur if cur < 0x80 else cur - 0x100) if match else 0x55, argbytes=0)
    e.hook(0x591b20, h591b20)
    hook_rec(c, 0x4f9680, 1, this=True, pop=4)
    return [me]


S(0x5b37e0, 'GUESS pick next usable input slot and notify the owner', 'thiscall', None, ret=None, gen=_g5b37e0, note='batch66090')

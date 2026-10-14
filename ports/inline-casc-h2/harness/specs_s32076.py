"""specs_s32076.py - h2 () batch 32076: 0x42f6e0, 0x5367c0. Callees hooked as recorders (0x4cc850 returns a precomputed sequence)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g42f6e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5f2d60, 2, this=True, pop=8)
    hook_rec(c, 0x431270, 1, this=True, pop=4)
    buf = rnd(c, 0x20)
    dst = rnd(c, 0x400)
    off = r.randrange(0, 0x100)
    e.w32(buf, dst + r.randrange(0, 0x40) if r.random() < 0.5 else dst)
    e.w32(buf + 4, dst + off)
    e.w32(buf + 8, (dst + off + 1) if r.random() < 0.6 else r.getrandbits(32))
    n = r.randrange(0, 12)
    text = bytearray(r.choice([b'abcxyz01', b'ab cd', b'a\tb', b'a$b', b'a\rb', b'a\nb', b'\x20']) for _ in range(1))[0] if False else bytearray()
    for _ in range(n):
        text.append(r.choice([r.randrange(1, 256), 0x20, 9, 0xd, 0xa, 0x24] if r.random() < 0.15 else [r.randrange(0x21, 0x7f)]))
    src = rnd(c, 0x40)
    e.wbytes(src, bytes(text))
    pp = rnd(c, 8)
    e.w32(pp, src)
    end = src + n if r.random() < 0.8 else src + r.randrange(0, 12)
    if r.random() < 0.05:
        end = src
    return [buf, pp, end]


def g5367c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x5400)
    off = r.choice([0, r.randrange(4, 0x80) * 4])
    b = me + 0x5302
    e.wbytes(b, off.to_bytes(4, 'little'))
    count = r.randrange(0, 6)
    base_blk = rnd(c, 0x400)
    # arr = base + off ; base chosen so that arr is inside the block
    base = base_blk - off if off else base_blk
    for i in range(count):
        # [ent + off + 4] must be readable -> ent + off + 4 within memory: put entries so
        ent_blk = rnd(c, 0x400 + off)
        e.w32(base_blk + 4 * i, ent_blk)
        e.w32(ent_blk + off + 4, rnd(c, 0x20))
    seq = [r.choice([0, 1, 2]) for _ in range(8)]
    hook_rec(c, 0x4cc850, 0, this=True, pop=0, ret=lambda emu, k: seq[min(k, 7)])
    s = rnd(c, 0x10)
    if r.random() < 0.15:
        e.wbytes(s, b'\0')
    sp = 0 if r.random() < 0.1 else s
    return [me, base, count, sp]


S(0x42f6e0, 'GUESS append token chars to growing buffer', 'stdcall', None, ret=None, gen=g42f6e0, note='batch32076')
S(0x5367c0, 'GUESS find first table entry accepted by matcher', 'thiscall', None, ret='eax', gen=g5367c0, note='batch32076')
